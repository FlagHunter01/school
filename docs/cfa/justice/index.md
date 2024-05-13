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

