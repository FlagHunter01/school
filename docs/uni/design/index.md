---
title: Security by design
description: cours de security by design
---


!!! info "Prof"
    Nadege REYNAUD

## Intro

- Comprendre la démarche de sécu par conception
- Mener une analyse de risques
- Faire le lien entre les aspects fonctionnels et opérationnels de la cybersécu d'une organisation (lien entre risques et failles)

!!! abstract "PSSI"

!!! abstract "Cybersécu"
    Protection, détection, réaction, ghestion de crise

!!! abstract "Humain"
    Formation, entrainement, sensibilisation

### Besoin d'anticipation

- Connaitre les menaces
- Maitriser les vulnérabilité (patch, mitigation des failles si impossible)
- Se protéger en conséquence (actions technique, utilisation d'outils spécifiques ou sensibilisation du personnel)

### Analyse de risques

- Se connaitre: contexte, activités, périmètre, écosystème, parties prenantes
- Connaitre ses activités critiques et ses données sensibles
- Evaluer les risques et savoir les priorétiser
- S'organiser en conséquence

### Analyse de risques cyber

- Se connaitre: contexte, activités, périmètre, écosystème, parties prenantes
- Connaitre ses systèmes critiques et ses données sensibles (savoir où elles se trouvent)
- Connaitre ses besoins de sécurité (dispo, intégrité, confidentialité, tracabilité) et de conformité
- Avoir conscience des menaces et des vulnérabilités
- Evaluer les risques et savoir lesquels traiter en priorité
- Etablir des plans de sécurisation et s'y tenir, gérer les risques.

## Security by design

Concevoir des produits et des logiciels fondamentalement sécurisés.
La sécurisation se réfléchit et s'opère dès la conception, en prenant en compte les risques.
Elle est anticipée.

### Où s'opère la secu by design?

- Code ([OWASP](https://owasp.org/www-project-developer-guide/draft/), DevSecOps)
- Architecture (ANSII)
- Projets (implémentation d'une nouvelle fonctionnalité) (EBIOS RM, ISP)
- Stratégies (ISO27001, NIST)

#### Le code

Eviter de générer des applis faillibles dès le départ.
Il faut considérer au plus tôt les aspects relatifs à la sécurité pour anticiper au maximum l'introduction de vulnérabilités.

##### DevSecOps

Intégration de la sécurité des applications plus tôt dans le cycle de développement.
Anticiper pour éviter la correction de vulnérabilités a posteriori, alors plus couteuse et plus compliquée.

##### OWAPS

Open WorldWide Applicatoon Security Project.

Travaille sur un guide pour les développeurs, mais également beaucoip de ressources. Les principes le plus souvent appliqués sont:

- Le moindre privilège
- La séparation des tâches
- La défense en profondeur
- Le principe de Zero Trust

#### Architecture

L'objectif est de protéger au mieux les systèmes critiques et les données sensibles d'une organisation, grâce à des principes d'architectures sécurisées.

Cela permet:

- d'éviter la propagation d'attaques
- de conserver un bon niveau de sécurité malgré les migrations
- de concevoir des architectures permettant de satisfaire les besoins de sécurité

#### Projets

L'activité principale réside dans l'analyse de risques.

Des méthodes existent, comme EBIOS RM, ou des normes comme ISO27005, mais on peut également construire sa propre méthode.

Les étapes fondamentales sont:

- Identifier les actifs
- Identifier le personnes responsables
- Identifier les vulnérabilités
- Identifier les menaces
- Identifier les impacts
- Evaluer la vraisemblance
- Evaluer les nivbeaux de risques

EBIOS RM: Expression des besoins et identification des objectifs de sécurité.
outil complet de gestion des risques SSI conforme au RGS et aux normes ISO27001 et 27005.
Elaboration par l'ANSSI et le Club EBIOS.

!!! abstract "Risque"
    Scénario qui combine un évènement redouté et un ou plusieurs scénarios de menaces. On estime son niveau par sa gravité (hauteur des impacts) et sa vraisemblance (possibilité qu'il se réalise).

!!! abstract "Identification du projet"
    Contexte, parties prenantes, enjeux métier, volume, dates clés, informations disponibles sur le projet informatique et ses composants, solutions, architecture

!!! abstract "Evaluation des besoins de sécurité"
    !!! warning "A compléter"

!!! abstract "Analyse des risques"
    !!! warning "A compléter"

!!! abstract "Traitement des risques
    !!! warning "A compléter"

!!! abstract "Plan d'actions de sécurité"
    !!! warning "A compléter"

##### ISP

- Identification: identification précoce des risques de cyber, des projets critiques et des mesures de sécurité indispensables
- Conformité: Garantir la conformité du système d'information vis-a-vis de la reglementation applicable et de la politique de sécurité interne
- Anticipation: anticiper les menaces et éviter les incidents de sécurité
- Business: couvrir les besoins de sécurité du métier

##### Détecter les projets

- Se faire connaitre: expliquer la démarche d'analyse de risques et les bénéfices attendus pour l'organisation
- Capter les projets:
    - Portefeuille projets
    - Connaitre les métiers (être présent dans les CoDir)
    - Traquer le shadow IT (les utilisateurs qui changent des choses sans passer par l'IT (outils louches, applications, automatisations via webapp ...))
    - Se positionner sur les outils (ITSM, méthodes projet, comités)

##### Contexte

Pour analyser les risques inhérents à un projet

##### Besoins de sécurité

- Disponibilité: Propriété d'être accessible et utilisable à la demande par une entité autorisée
- Intégrité: Propriété de protection de l'exactitude et de l'exhaustivité de l'information
- Confidentialité: Propriété selon laquelle l'information n'est pas rendue accessible ou divulguée à des personnes, entités ou processus non autorisés
- Tracabilité: Besoin de pouvoir retrouver le cheminement de l'information tout au long de la chaîne de traitement et de transmission, avec une garantie de fiabilité donnant à ces traces une valeur de preuve

Il faut qualifier les conséquences, les impacts de la perte de l'un de ses critères. 

Vérifier l'implication de conformité (RGPD, RGS, PCI-DSS-DORA ...) 

##### Mesure des critères de sécurité

- Disponibilité: se mesure en fonction de la Durée d'Indisponibilité Maximale Admissible (DIMA)
- Intégrité: Se mesure en termes de capacité à détecter une modification et à la réparer
- Confidentialité: Se mesure en termes de diffusion acceptable de l'information
- Preuve: se mesure en termes de besoin d'imputabilité

## Ateliers analyse de risques

1. Cadrage / socle de sécurité
2. Sources de risque (carthographie)
3. Scénarios stratégiques (définition des chemins d'attaque d'après les sources de risques)
4. Scénarios opérationnels (détail de ce qui est faillible sur les sytèmes)
5. Traitement du risque
