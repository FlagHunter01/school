---
title: Cryptographie post quantique
description: Cours de crypto post quantique
---

!!! info "Prof"
    G. Renault

!!! note "Partie historique"
    Je suis arrivé a 10h, j'ai raté cette partie :smile:


## Partie 3 

### DES

- Block ciphering
- Se rapprocher le plus possible du chiffrement parfait
- Faire un cipher appliquable a une grande quantité de blocs sans créer de fuite statistique
    - Confusion: un bit du message dépend de plusieurs bits de la clé avec un rapport polynomial
    - Diffusion: chaqu bit du claire influe sur beaucoup de bits chiffrés
- Shema de Feistel: réplication de la même fonction de chiffrement avec évolution de la clé. 
- Attaques différentielles sur les boites S (je suis officiellement largué)
- DES est pété a cause de la taille de sa clé
- On passe sur 3DES car il est compliqué de faire évoluer toute l'infra existante. On utilise 2 clés, en remettant la 1^e^ a la fin (1-2-1). 

### AES

- Clé d'au moins 128 bits
- Peu gourmand en ressources, expansion de clé optimisé
- Système ded fonctionnement impossible a résumer, look it up
- En doublant la taille de la clé, on reste indéchiffrable par les ordinateurs quantiques les plus puissants qui pourraient potentiellement exister (?)

!!! warning "Après j'ai arrêté de prendre des notes lol"
