SELECT APNT_NO,PT_NAME,a.PT_NO,a.MCDP_CD,DR_NAME,APNT_YMD 
from (appointment as a inner join patient as b
on a.pt_no = b.pt_no) inner join doctor as c
on mddr_id = dr_id
where date_format(apnt_ymd,'%Y-%m-%d') = '2022-04-13' 
and APNT_CNCL_YN = 'N' 
and a.mcdp_cd = 'CS'
order by apnt_ymd;