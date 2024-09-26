SELECT a.PRODUCT_ID,PRODUCT_NAME,sum(price*amount) as TOTAL_SALES
from food_order as a inner join food_product as b on a.product_id = b.product_id
where date_format(a.produce_date,'%Y-%m') = '2022-05'
group by a.product_id
order by total_sales desc,a.product_id;