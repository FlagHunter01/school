---
title: Virtualisation - rapport
description: Rapport pour le cours de virtualisation
---

!!!info inline end "Prof"
    Thierry DECKER<br>
    [Mail](mailto:mail@thierry!-decher.com)

## Création de la VM

### Prérequis

 - [VirtualBox](https://www.virtualbox.org/wiki/Downloads)
 - [Debian](https://www.debian.org/download)

### Allocation de ressources

On peut supposer avec assurance que les VMs ne vont pas faire tourner de processus lourds, mais que nous serons amenés a en exploiter plusieures simultanément.
N'ayant pas besoin d'interface graphique, nous préfèrerons donc assigner le moins de ressources possible.
Ainsi, choisir lors du paramétrage:

 - 1 ou 2 CPUs
 - 2Go de RAM
 - La taille réele du disque est variable (il ne prend que l'espace nécessaire pour stocker ses données), on peut donc garder la valeur par défaut.

### Installation de la machine

!!! warning "Sur VirtualBox, cocher la case "Skip fast installation" pour pouvoir contrôler l'installation de la VM."

Installer le système avec les valeurs proposées par défaut excepté les instances suivantes:
 - Renseigner "france" / "Français" pour toutes les questions de localisation et de clavier pour éviter les problèmes d'incompatibilité clavier et NTP.
 - Vers la fin de l'installation, un menu coche par défaut l'environnement bureau ainsi qu'un interface graphique (Gnome ou XFace d'habitude). Décocher toutes les cases.

Si l'installation s'est bien terminée, la machine redémarre et donne le prompt.

!!! abstract "Configuration usuelle"
    J'ai l'habitude de configurer `.bashrc` et télécharger `vim` sur les OS vièrges avant de commencer à travailler dessus.
    Ceci permet d'optimiser le temps de travail et d'ajouter un confort visuel.

## Installation des logiciels demandés

!!! inline end note "Note"
    J'utilise `apt` car `aptitude` ne dispose pas des "supercow powers":
    ```
    aptitude moo
    aptitude -v moo
    aptitude -vv moo
    ...
    ```

Nous devons télécharger `ssh`, `net-tools` et `tcpdump`.

```
apt install ssh
apt install net-tools
apt install tcpdump
```

Tous ses outils fonctionnent *out of the box*, nous n'allons donc pas les configurer pour le moment.

## Création du réseau demandé

### Shéma

![schema](schema.png)

#### SRV1

| Adaptateur | Type | Interface | Statique ou dynamique | IP |
|---|---|---|---|---|
| 1 | NAT | enp0s3 | Dynamique | Dynamique |
| 2 | Réseau interne | enp0s8 | Statique | 172.22.0.1 |

#### SRV2

| Adaptateur | Type | Interface | Statique ou dynamique | IP |
|---|---|---|---|---|
| 1 | Réseau interne | enp0s3 | Statique | 172.22.0.2 |

### SRV1

!!! abstract "Interfaces de la VM"
    Cette VM possède deux interfaces:

     - Une en NAT
     - L'autre en réseau interne

Ce serveur est responsable du service de NAT.

#### Préparation du serveur

Il faut définir une IP statique pour l'interface LAN affin qu'il puisse servir de passerelle aux clients.

Sur mon serveur, l'interface WAN est enp0S3 et l'interface LAN est enp0s8.
Il faut donc modifier la partie de la configuration qui concerne ce dernier interface

```title="/etc/network/interfaces - partie relative à enp0s8"
auto enp0s8
iface enp0s8 inet static
address 172.22.0.1/22
```

Il faut ensuite autoriser le forwarding de paquets au niveau du système.<br>
Pour celà, décommenter la ligne qui suit puis rafraichir la configuration:

```title="/etc/sysctl.conf" linenums="28"
net.ipv4.ip_forward = 1
```
```
sysctl -p /etc/sysctl.conf
```

Enfin, noter l'IP externe du serveur en regardant la partie `enp0s3` du résultat de la commande:

```
ip a
```

#### Configuration de nftables

`nftables` est un sous-système du noyeau depuis Linux 3.13. C'est l'outil de filtrage de paquets par défaut.

En plus d'être très bien supporté, il reprend la structure de `iptables` et est facile d'utilisation.

S'il n'est pas déjà présent, l'installer:

```
apt install nftables
```

Ensuite, il faut:

 - Créer la table de NAT
 - Ajouter un hook au préroutage qui accepte les paquets
 - Ajouter un hook au post-routage qui accèpte les paquets et remplace les IP LAN par l'IP WAN du serveur.

Ceci est faisable en ajoutant ce qui suit au fichier de configuration de `nftables` puis en démarrant le service.

```title="A la suite de /etc/nftables.conf" linenums="17"
table nat {
   chain prerouting {
      type nat hook prerouting priority 0; policy accept;
   }
   chain postrouting {
      type nat hook postrouting priority 100; policy accept;
      oif enp0s3 masquerade;
   }
}
```
```
systemctl start nftables
```


### SRV2

!!! abstract "Interfaces de la VM"
    Cette VM possède une interface qui est dans le réseau interne.

Le SRV2 est une machine vièrge identique à l'état initial de SRV1, mais avec une seule interface.

#### Vérification du fonctionnement du réseau

```
ping 172.22.0.1
ping 8.8.8.8
```

#### Préparation du serveur

Puisque le serveur propose un service DHCP, il doit avoir une IP fixe.
On modifie donc la configuration réseau.

```title="/etc/network/interfaces" linenums="1"
auto lo
iface lo inet loopback

auto enp0s3
iface enp0s3 inet static
address 172.22.0.2/22
gateway 172.22.0.1
```

#### Configuration du DHCP

!!!warning "A compléter"

## Sources

 - [Nftables](https://wiki.nftables.org/wiki-nftables/index.php/Performing_Network_Address_Translation_(NAT))
