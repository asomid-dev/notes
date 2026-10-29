# Parcial 2025-2026 Primavera
#bd #examen #PARCIAL1 

Considereu l'esquema de la base de dades següent:
```sql
CREATE TABLE cliniques (
	idClinica INTEGER,
	nomClinica VARCHAR(100) UNIQUE NOT NULL,
	ciutat VARCHAR(100),
	pressupostAnual FLOAT CHECK (pressupostAnual > 0),
	PRIMARY KEY (idClinica));
	
CREATE TABLE metges (
	idMetge INTEGER,
	nom VARCHAR(100) UNIQUE NOT NULL,
	especialitat VARCHAR(50) NOT NULL,
	sou FLOAT CHECK (sou > 0),
	idClinicaActual INTEGER NOT NULL,
	PRIMARY KEY (idMetge),
	FOREIGN KEY (idClinicaActual) REFERENCES cliniques);
	
	--idClinicaActual és on actualment exerceix el metge
	
CREATE TABLE pacients (
	idPacient INTEGER,
	nom VARCHAR(100) NOT NULL,
	edat INTEGER CHECK (edat BETWEEN 0 AND 120),
	ciutat VARCHAR(100),
	PRIMARY KEY (idPacient));
	
CREATE TABLE tractaments (
	idClinica INTEGER,
	codiTractament INTEGER,
	descripcio VARCHAR(200),
	preuBase FLOAT,
	PRIMARY KEY (idClinica, codiTractament),
	FOREIGN KEY (idClinica) REFERENCES cliniques);
	
	-- Hi ha una fila per cada tractament ofert en la clínica

CREATE TABLE visites (
	idPacient INTEGER,
	idClinica INTEGER,
	codiTractament INTEGER,
	dataHora TIMESTAMP,
	idMetgeTractant INTEGER NOT NULL,
	idMetgeSolicitor INTEGER,
	PRIMARY KEY (idPacient, idClinica, codiTractament, dataHora),
	FOREIGN KEY (idPacient) REFERENCES pacients,
	FOREIGN KEY (idClinica, codiTractament)
	REFERENCES tractaments,
	FOREIGN KEY (idMetgeTractant) REFERENCES metges,
	FOREIGN KEY (idMetgeSolicitor) REFERENCES metges);
	
	-- idMetgeTractant: és qui realitza el tractament.

	-- El metge tractant exercia a la clínica en el moment del tractament.
	
	-- idMetgeSolicitor: és qui recomana o envia el pacient a la visita.
	
	-- Té valor NULL si el pacient no és enviat per cap metge.
```

## 1. (3 punts)

**1.1.** Doneu una sentència SQL per obtenir el nom i la ciutat de les clíniques que
ofereixen més de tres tractaments amb un preu base superior a 100€, i en les
quals cap dels metges que actualment hi exerceixen cobra més del doble de la
mitjana de sous de tots els metges de la base de dades.

```sql
select c.nomClinica, c.ciutat
from cliniques c, tractaments t
where c.idClinica = t.idClinica and t.preuBase > 100 and not exists(
	select m.idClinicaActual
	from metges m
	where m.idClinicaActual = c.idClinica and m.sou > (
		select 2*AVG(sou) 
		from metges)
	
)
group by c.nomClinica, c.ciutat
having count (*) > 3
```

**1.2.** Doneu una asserció que garanteixi que cap clínica tingui més pacients
diferents que s'han visitat a la clínica que el doble del nombre de tractaments
que la clínica ofereix.

```sql
create assertion menys_pacients_que_trats check (
	not exists (
		select *
		from visites v
		group by v.idClinica
		having count(distinct v.idPacient) > 2*(
			select count(t.codiTractament)
			from tractaments t
			where v.idClinica = t.idClinica
		) 
	)
);
```

## 2. (2 punts)
Doneu una seqüència d'operacions d’àlgebra relacional per obtenir el
nom i l'especialitat dels metges que en tota la seva activitat únicament han fet
visites com a metges tractants de pacients jubilats (de 65 anys o més) i que, a
més, han exercit exclusivament a la clínica "EL REMEI". En el resultat de la
consulta només han de sortir metges que hagin fet alguna visita com a metges
tractants.

```sql
# A = pacients(edat < 65)
B = A*visites -- VISITES DE PACIENTS < 65 ANYS
C = cliniques(nomClinica <> 'EL REMEI')
D = C[idClinica]
E = D*visites -- VISITES DE CLINIQUES <> EL REMEI
F = B[idMetgeTractant] -- F -> idMetges de Visites -65 anys
G = E[idMetgeTractant] -- G -> idMetges de visites que no son a el remei
H = visites[idMetgeTractant]
I = H - F
J = I - G
K = metges[idMetge = idMetgeTractant]J
R = K[nom, especialitat]
```

## 3. (2 punts)
Suposeu que l’Ona és la propietària de la base de dades.

**3.1.** Doneu el diagrama d’autoritzacions resultant d’executar les sentències següents:
```sql
Ona: GRANT SELECT(nom,especialitat) ON metges TO Albert WITH GRANT OPTION;
Ona: GRANT SELECT(sou) ON metges TO Berta;
Ona: GRANT SELECT(nom) ON metges TO Berta WITH GRANT OPTION;
Albert: GRANT SELECT(nom,especialitat) ON metges TO Berta WITH GRANT OPTION;
Albert: GRANT SELECT(especialitat) ON metges TO Carles;
Berta: GRANT SELECT(nom) ON metges TO Carles WITH GRANT OPTION;
Carles: GRANT SELECT(nom) ON metges TO Diana;
```

**Fet a paper**

**3.2.** A continuació s'executen les dues sentències següents (en l'ordre presentat).
Doneu dos diagrames d'autoritzacions: el resultant després del primer REVOKE i
el resultant després del segon. Per a cadascun, justifiqueu quins privilegis guanyen
o perden l'Albert, la Berta, en Carles i la Diana i per quin motiu.
```sql
Ona: REVOKE SELECT(nom) ON metges FROM Albert CASCADE;
Ona: REVOKE SELECT(nom) ON metges FROM Berta CASCADE;
```

**Fet a paper**

**3.3.** L'Ona vol que en Marc pugui fer totes les operacions següents definint la mínima
quantitat de vistes i donant al Marc els privilegis mínims necessaris sobre les
vistes: 
- Inserir visites en què el pacient hi va pel seu compte (idMetgeSolicitor és NULL) i consultar totes les columnes d'aquestes visites. Les insercions han de garantir que les noves files siguin visibles a la vista.
- Consultar el nom i l'especialitat dels metges tractants de les visites on els pacients hi van pel seu compte.
- Modificar únicament l'atribut idMetgeTractant de les visites on els pacients hi van pel seu compte.
**COM A RESPOSTA CAL DONAR:**
- Les sentències CREATE VIEW i GRANT corresponents.
- Per a cada vista, justificar si és actualitzable o no, indicant quins elements de la definició ho determinen.
- Per a cada vista, justificar si cal WITH CHECK OPTION o no.

```sql
create view pelSeuCompte as
	select *
	from visites v
	where v.idMetgeSolicitor is null
	with check option;

grant select, insert on pelSeuCompte to Marc;
grant update(idMetgeSolicitor) on pelSeuCompte to Marc;

create view metgePelSeuCompte as
	select m.nom as nomMetge, m.especialitat
	from metges m, pelSeuCompte psc
	where psc.idMetgeTractant = m.idMetge;

grant select on metgePelSeuCompte to Marc;
```

## 4. (3 punts)
**Donat el model conceptual en UML següent, es demana fer la traducció a model relacional donant el disseny lògic de la base de dades resultant. Concretament cal indicar:**

- taules
- atributs
- claus primàries
- claus foranes
- restriccions NOT NULL per a les claus foranes que ho requereixin
- restriccions UNIQUE en cas d’existir claus alternatives
- **Restriccions de columna o de taula per a implementar R1, R2, R3, R4. En cas que alguna d’aquestes restriccions no es pugui implementar com a restricció de columna o de taula, explicar perquè no es pot.**

![[2026-04-09.png]]

Restriccions textuals següents:
- Clau externa **Plataforma**: acrònim
- Clau externa **Usuari**: nomUsuari
- Clau externa **Instant**: instantEnviament
- Clau externa **Missatge**: idMissatge (en el disseny d’aquesta BD s’ha decidit afegir una clau externa per facilitar la identificació dels missatges, tot i tractar-se d’una classe associativa).
- Clau externa **Perfil**: No poden existir dos perfils amb el mateix nomUsuari
- Clau externa **Esdeveniment**: títol, any
- Clau externa **Escenari**: No poden existir escenaris amb un mateix nomEscenari en un mateix esdeveniment, però si en esdeveniments diferents.
- Clau externa **Hora**: data, horaInici
- **R1**: L'estat d'una assistència només pot ser 'confirmada' o 'cancel·lada'
- **R2**: Si una assistència està en estat confirmada, aleshores ha de tenir una data de registre diferent de null
- **R3**: Les actuacions en un esdeveniment han de ser en escenaris contractats per aquest esdeveniment
- **R4**: No hi pot haver dues plataformes amb el mateix nom


```sql
plataformes(acronim, nomPlataforma)
    UNIQUE(nomPlataforma) -------------> /*R4*/                                    
usuaris(nomUsuari, password, idPlataforma)
    {idPlataforma} referencia plataformes(acronim)
    NOT NULL(idPlataforma)

perfils(nomUsuari, nom, foto)
    {nomUsuari} referencia usuaris

missatges(idMissatge, idMissatgeRespost, 
          instantMissatge, nomUsuariEnvia, nomUsuariRep, 
          text)
    {idMissatgeRespost} referencia missatges
    UNIQUE(instantMissatge, nomUsuariEnvia)
    UNIQUE(instantMissatge, nomUsuariRep)
    NOT NULL(instantMissatge, nomUsuariEnvia, nomUsuariRep)

esdeveniments(titol, any, descripcio, idPlataforma)
    {idPlataforma} referencia plataformes(acronim)
    NOT NULL(idPlataforma)

assistencies(nomUsuari, titol, any, estat, dataRegistre)
    {nomUsuari} referencia usuaris
    {titol, any} referencia esdeveniments
    CHECK (estat IN ('confirmada', 'cancel·lada'))------------> /*R1*/
    CHECK (estat!='confirmada' OR dataRegistre IS NOT NULL)---> /*R2*/

escenaris(nomEscenari, titol, any, situació)
    {titol, any} referencia esdeveniments

actuacions(data, horaInici, nomEscenari, titol, any, 
           titolEsdeveniment, anyEsdeveniment, 
           durada, descripcio)
    {nomEscenari, titol, any} referencia escenaris
    {titolEsdeveniment, anyEsdeveniment} referencia esdeveniments
    NOT NULL(titolEsdeveniment, anyEsdeveniment)
    CHECK(titol = titolEsdeveniment AND Any = anyEsdeveniment) -----> /*R3*/
```


```sql


```