---
title: PROJET
description: C'EST NOTRE PROJET!
---

!!! tip "[DL MON DELIRE ICI](conf_base.pkt)"

## Site local

### R1

```
en
conf t
hostname R1
no ip domain lookup
enable secret OATE
banner motd #R1#

int GigabitEthernet0/0/0
description LAN
ip address 172.16.1.252 255.255.255.0
no shut
exit

int GigabitEthernet0/0/1
description WAN
ip address 80.0.0.1 255.255.255.0
no shut
exit

ip route 10.10.10.0 255.255.255.0 80.0.0.3
ip dhcp excluded-address 172.16.1.201 172.16.1.255
ip dhcp pool local
network 172.16.1.0 255.255.255.0
default-router 172.16.1.252
exit
exit
wr
```

### R2

!!! warning "Shut pour l'instant."

```
en
conf t
hostname R2
no ip domain lookup
enable secret OATE
banner motd #R2#
int GigabitEthernet0/0/0
description LAN
ip address 172.16.1.253 255.255.255.0
shut
exit
int GigabitEthernet0/0/1
description WAN
ip address 80.0.0.2 255.255.255.0
shut
exit
ip route 10.10.10.0 255.255.255.0 80.0.0.3
ip dhcp excluded-address 172.16.1.201 172.16.1.255
ip dhcp pool local
network 172.16.1.0 255.255.255.0
default-router 172.16.1.252
exit
exit
wr
```

### S1

!!! fail "Rien pour l'instant"

## Site distant

### RA

```
en
conf t
hostname RA
no ip domain lookup
enable secret OATE
banner motd #RA#
int GigabitEthernet0/0/0
description WAN
ip address 80.0.0.3 255.255.255.0
no shut
exit
int GigabitEthernet0/0/1
description LAN
ip address 10.10.10.254 255.255.255.0
no shut
exit
ip route 172.16.1.0 255.255.255.0 80.0.0.1
ip dhcp excluded-address 10.10.10.201 10.10.10.255
ip dhcp pool distant
network 10.10.10.0 255.255.255.0
default-router 10.10.10.254
exit
exit
wr
```

### SA

!!! fail "Rien pour l'instant"
