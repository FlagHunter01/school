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
- COmme pour arping, on utilise `cut` et `tr` pour isoler l'IP du résultat
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

#### Phase active

