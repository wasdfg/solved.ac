SELECT b.ANIMAL_ID,b.ANIMAL_TYPE,b.NAME 
from animal_ins as a inner join animal_outs as b on a.animal_id = b.animal_id
where a.SEX_UPON_INTAKE like 'Intact%' and (b.SEX_UPON_outcome like 'Spayed%' or b.SEX_UPON_outcome like 'Neutered%')
order by animal_id