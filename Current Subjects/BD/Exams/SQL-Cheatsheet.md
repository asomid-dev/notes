# SQL Cheatsheet
#bd #apunts #PARCIAL1 
## Create Table
```sql
CREATE TABLE usuaris (
    idUsuari INTEGER,
    nom CHAR(50) NOT NULL,
    email CHAR(100) UNIQUE,
    PRIMARY KEY (idUsuari),
    FOREIGN KEY (email) REFERENCES correus(email) ON DELETE CASCADE
);
```

## Create Table (amb Select)
```sql
CREATE TABLE coordinadors_vic AS 
SELECT * 
FROM persones 
WHERE ciutat = 'Vic';
```

## Insert
```sql
INSERT INTO usuaris (idUsuari, nom, email) 
VALUES (1, 'Anna', 'anna@example.com');
```

## Insert (amb Select)
```sql
INSERT INTO historica_inscrits (nom, email)
SELECT p.nom, p.email 
FROM persones p 
	 INNER JOIN inscripcions i ON p.email = i.inscrit;
```

## Update
```sql
UPDATE usuaris 
SET nom = 'Anna Maria' 
WHERE idUsuari = 1;
```

## Update (amb Select)
```sql
UPDATE usuaris 
SET estat = 'Actiu' 
WHERE idUsuari IN (
    SELECT inscrit 
    FROM inscripcions 
    WHERE idCongres = 'C1'
);
```

## Delete
```sql
DELETE FROM usuaris 
WHERE idUsuari = 1;
```

## Delete (amb Select)
```sql
DELETE FROM persones 
WHERE email NOT IN (
    SELECT inscrit 
    FROM inscripcions
);
```

## Create View
```sql
CREATE VIEW vista_coordinadors_vic AS 
SELECT p.nom, p.email, a.nomActivitat 
FROM persones p 
INNER JOIN activitats a ON p.email = a.coordinador 
WHERE p.ciutat = 'Vic';
-- WITH CHECK OPTION; --> TOTS ELS INSERTS I UPDATES HAN DE COMPLIR AMB EL WHERE
```

## Grant Permission
```sql
GRANT SELECT, INSERT, UPDATE ON persones TO nom_usuari;
```

```sql 
-- Per donar permisos de cedir permisos a tercers.
GRANT SELECT, UPDATE ON persones TO nom_usuari WITH GRANT OPTION;
```

## Revoke Permission
```sql
REVOKE SELECT, UPDATE ON persones FROM nom_usuari;
```

```sql
-- Si vols que s'esborrin també els permisos en cadena cedits a tercers:
REVOKE SELECT, UPDATE ON persones FROM nom_usuari CASCADE; 
```

```sql
-- Si vols que falli si l'usuari ha compartit permisos amb algú altre:
REVOKE SELECT, UPDATE ON persones FROM nom_usuari RESTRICT; 
```

## Inner Join (Unió explícita)
```sql
SELECT p.nom, a.nomActivitat 
FROM persones p 
INNER JOIN activitats a ON p.email = a.coordinador; 
-- Retorna les files que compleixen amb aquestes condicions
```

## Natural Inner Join (Unió implícita)
```sql
SELECT * 
FROM persones p 
NATURAL INNER JOIN inscripcions i;
-- Fa el mateix que inner join, però busca columnes amb el mateix nom
```

## Algebra Relacional
```sql
R = persones(ciutat = 'Vic')             -- Selecció
R = persones[nom, email]                 -- Projecció
R = T _u_ S                              -- Unió
R = T _n_ S                              -- Intersecció
R = T - S                                -- Diferència
R = T _x_ S                              -- Producte Cartesià
R = T[ciutat = ciutat2, ciutat = 'Vic']S -- Combinació (Theta Join)
R = T[ciutat*ciutat2]S                   -- Natural Join Explícita
R = T*S                                  -- Natural Join Implícita
```