---
title: Digital Forensic Science
description: Cours Digital Forensic Science
---

!!! warning "J'ai raté la première demi-journée jusqu'à la pause"

## Etapes d'une analyse forensic

L'objectif est de réaliser une série d'étapes pour préserver la preuve afin qu'elle puisse être acceptable en procès (forensically sound).

Il existe plusieurs types d'infractions dont l'investigation diffère:

- Infraction informatique - Atteinte a un STAD
- Infraction non-informatique où un support informatique peut fournir des informations.

La chain of custody est une chaine qui permet de tracer les intéractions de tout le monde avec le scellé.

### Identification

- Dump de RAM

### Aquisition

- Copie des disques durs (``dd`` par exemple)
- Utilisation de bloqueurs en écriture (Câble qui laisse passer la data dans un seul sens (avec une sorte de DEL sur le connecteur data du port))
- On hash les dumps effectués pour vérifier qu'ils ne bougent pas (modifs accidentelles par exemple)

### Préservation

Toute se fait hors ligne, le PC d'analyse est chiffré et les serveurs de stockage sont dédiés et sécurisés un max.

### Analyse

- Tri et classification de la donnée brute. 
- Un premier raffinage se fait automatiquement avec un logiciel qui lit les partions etc.
- Ensuite les données sotn analysées manuellement, c'est cette partie qui a de la plusvalue. 
- Lecture des fichiers de cache.
- Artefacts d'applis (medias, logs, historiques, artéfacts de navigation et de système (dernier emplacment de sauvegarde via clé de registre par exemple)).
    - Tout ceci prend beaucoup de temps.

### Présentation

- Rédaction d'un rapport direct et factuel, sans émttre de jugement / interprétation.
- Il vaut mieux donner trop d'infos que pas assez

## Tsurugi

- Kali du forensic (DFIR), il faut connaitre les outils pour pouvoir s'en servir. 
- Une tonne d'outils

## Computer forensics

### Récupération des données

- EWF: compresse les images extraites. Super pour les disques qui n'ont pas été remplis jusqu'au bout.

### Aquisition et préservation (TP)

### Theorie sur la récupération des données

### Présentation d'artéfacts spécifiques

### Autopsy

### TP

Pour voir les instantanés cachés du système:
```
vssadmin list shadows
```

Pour y accéder, il faut créer un soft link avec le CMD:
```
cd <ou tu veux le lien>
mklink \d shadowcopy \\?\GLOBALROOT\Device\XXX\
```
