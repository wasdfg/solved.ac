SELECT food_product.category,food_product.price,product_name 
from food_product inner join 
(select max(price) as price,category 
 from food_product group by category) as a 
 on food_product.category = a.category and food_product.price = a.price
where food_product.category in ('과자','국','김치','식용유')
order by food_product.price desc;