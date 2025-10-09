#!/bin/bash
#
# CPU Architecture
arc=$(uname -a)

# Physical processors
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 

# Number of cores
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)

# RAM. Free, used and % used
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf(%.2f), $3/$2*100}')

# Disks space used
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{free += $2} END {print free}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} END {print used}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} {free+= $2} END {printf("%d"), used/free*100}')

# CPU use
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')

# Last reboot time and date
lb=$(who -b | awk '$1 == "arranque" {print $5 " " $4}')

# LVMU Info
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)

# Connections TCP 
ctcp=$(ss -Ht state established | wc -l)

# Users
ulog=$(users | wc -w)

# Ip del host
ip=$(hostname -I)

# Physical address
mac=$(ip link show | grep "ether" | awk '{print $2}')

# sud executions
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"

