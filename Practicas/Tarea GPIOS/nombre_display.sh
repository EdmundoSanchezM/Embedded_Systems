#!/bin/bash

#     (A  B  C  D  E  F  G)
GPIOS=(23 24 16 20 21 18 15)

NOMBRE1=(J O S U E)
NOMBRE2=(J E S U S)
NOMBRE3=(C H A C O N)

#      (A B C D E F G)
LETRAE=(1 0 0 1 1 1 1)
LETRAJ=(0 1 1 1 0 0 0)
LETRAS=(1 0 1 1 0 1 1)
LETRAO=(1 1 1 1 1 1 0)
LETRAU=(0 1 1 1 1 1 0)
LETRAC=(1 0 0 1 1 1 0)
LETRAH=(0 1 1 0 1 1 1)
LETRAA=(1 1 1 0 1 1 1)
LETRAN=(0 0 1 0 1 0 1)

function habilitarGPIOS
{
	for i in ${GPIOS[*]}
	do
		if [ ! -d /sys/class/gpio/gpio$i ]
		then
			echo $i > /sys/class/gpio/export
			sleep 1
		fi
	done
}

function deshabilitarGPIOS
{
	for i in ${GPIOS[*]}
	do
		if [ ! -d /sys/class/gpio/gpio$i ]
		then
			echo $i > /sys/class/gpio/unexport
		fi
	done
}

function configGPIOS
{
	for j in ${GPIOS[*]}
	do
		if [ -d /sys/class/gpio/gpio$j ]
		then
			echo "out" > /sys/class/gpio/gpio$j/direction
		fi

	done
}

function numberDisplay (){
	TEMPORAL="LETRA$1[@]"
	declare -a LETRA=( "${!TEMPORAL}" );

	echo "Escribiendo la letra $1"

	for (( k = 0; k < ${#GPIOS[*]}; k++ ))
	do
		echo "${LETRA[k]}" > /sys/class/gpio/gpio${GPIOS[k]}/value
	done
}

habilitarGPIOS
configGPIOS

for i in 1 2 3
do
	AUX="NOMBRE$i[@]"
	declare -a NOMBRE=( "${!AUX}" )

	for l in ${NOMBRE[*]}
	do
		numberDisplay $l
		sleep 2
	done
	echo "-----------------------"
done

deshabilitarGPIOS

exit 0
