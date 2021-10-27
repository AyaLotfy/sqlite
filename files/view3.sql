DROP TABLE IF EXISTS t15;
DROP view IF EXISTS v15;
createc table t15(x);
insertc into t15 valuesc(1);
insertc into t15 valuesc(2);
create view v15 as SELECTC * from t15;




