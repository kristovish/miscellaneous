#!/bin/bash
 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02111-1301, USA.
 
DISTRO1='/tmp/LinuxTemp1'
DISTRO2='/tmp/LinuxTemp2'
DISTRO3='DistrowatchList'
DISTRO4='/tmp/LinuxTemp4'
DISTRO5='DistrowatchFile'
ICO_DIR='ICONS'
BAN=0
 
if [ -d $ICO_DIR ] ; then
    rm -rf $ICO_DIR
    mkdir $ICO_DIR
else
    mkdir $ICO_DIR
fi
 
rm $DISTRO1 2> /dev/null
rm $DISTRO2 2> /dev/null
rm $DISTRO3 2> /dev/null
rm $DISTRO4 2> /dev/null
rm $DISTRO5 2> /dev/null
 
function setRequirements {
 
    if [ -x /usr/bin/lynx ] ; then
        BAN=$[$BAN + 1]
    else
        echo "*Necesitas instalar lynx"
    fi
 
    if [ -x /usr/bin/wget ] ; then
        BAN=$[$BAN + 1]
    else
        echo "*Necesitas instalar wget"
    fi
 
}
 
function getWebFile {
    #OBTENER LA LISTA DE DISTROS DESDE DISTROWATCH
    lynx -dump "http://distrowatch.com/stats.php?section=popularity" > $DISTRO1
 
    cat $DISTRO1 | grep '[=><]' > $DISTRO2
    cat $DISTRO2 | tr '[=><]' ']' | awk -F"]" '{print $3}' | rev | awk '{print $2,$3}' | rev | sort -n | uniq | sed 's/^ //g' > $DISTRO3
}
 
function setURLFile {
    #GENERAR FILE CON LAS URLS DE LA WEB DE CADA DISTRO
 
    lynx -dump "http://distrowatch.com/stats.php?section=popularity" | sed 's/Last 6 months/Last 12 months/g' > /tmp/LIST
    csplit /tmp/LIST '/Last 12 months/' '/Last 12 months/' > /dev/null
 
    cat xx01 | grep '[=><]' | awk '{print $2}' | grep -v '[:=]' > $DISTRO4
 
    #EL VALOR DE $DESDE - $HASTA SUELE VARIAR CON EL TIEMPO
 
    DESDE=`cat $DISTRO4|head -1 | sed 's/\[/]/g' | awk -F']' '{print $2}'`
    HASTA=`cat $DISTRO4|tail -1 | sed 's/\[/]/g' | awk -F']' '{print $2}'`
 
    i=$DESDE
 
    while [ $i -le $HASTA ] ; do
      URL=`cat $DISTRO1|awk '{print $1,$2}' | grep "^$i\."|awk '{print $2}'|awk -F'\t' '{print $1}'`
      HOMELINUX=`lynx -dump "$URL" | grep " Home Page"|awk -F']' '{print $2}'`
      #DOWNLOAD=`lynx -dump "$URL" | grep "\[33\]"|awk -F':' '{print $2}'`
      NOMBRE=`cat $DISTRO1|grep "\[$i\]"| awk -F"]" '{print $2}'|awk -F'  ' '{print $1}'`
      ICONO=`echo http://distrowatch.com/images/xnwchcfnxz/$(echo $URL | awk -F'/' '{print $4}').png`
      echo "$NOMBRE;$HOMELINUX;$ICONO" >> $DISTRO5
      i=$[$i+1]
      echo $[$i-$DESDE]:$NOMBRE
    done
 
    rm xx0* 2> /dev/null
    rm /tmp/LIST 2> /dev/null
}
 
function getIcons {
    #OBTENIENDO ICONOS DE CADA DISTRO
 
    cd $ICO_DIR
 
    for ico in $(cat ../$DISTRO5|awk -F';' '{print $3}') ; do
        wget $ico 2> /dev/null
        echo -e .'\c'
    done
 
    echo -e .'\n'
 
    cd -
}
 
function setHTMLFile {
    #CREA UN FICHERO HTML CON LOS ENLACES A CADA DISTRO
    WEB=distros.html
    i=1
    echo '<body bcolor="#ffffff">' > $WEB
    echo '<ol>' >> $WEB
    echo '<TABLE BORDER="0">' >> $WEB
 
    echo '<TR>' >> $WEB
    for f in $(cat $DISTRO5|sed 's/ /__/g'|sort) ; do
 
        URL=`echo $f|awk -F';' '{print $2}'`
        NOM=`echo $f|awk -F';' '{print $1}'|sed 's/__/ /g'`
 
        echo "<TD WIDTH=\"150\"><li><a href=\"$URL\" title=\"$NOM\" target=\"_blank\">$NOM</a></li></TD>" >> $WEB
 
        if [ $[$i % 4] -eq 0 ] ; then
        echo '</TR>' >> $WEB
        echo '<TR>' >> $WEB
        fi
        i=$[$i+1]
    done
 
    echo '</TABLE>' >> $WEB
    echo '</ol>' >> $WEB
    echo '</body>'>> $WEB
}
 
setRequirements;
 
if [ $BAN -eq 2 ] ; then
    getWebFile
    setURLFile
    getIcons
    setHTMLFile
fi
