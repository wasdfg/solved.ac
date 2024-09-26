select a.id,a.genotype,b.genotype as parent_genotype
from ecoli_data as a left join ecoli_data as b
on a.parent_id = b.id
where (a.genotype & b.genotype) = b.genotype
order by a.id;