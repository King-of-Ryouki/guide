-- 從數據庫中選取數據。
-- 結果被存儲在一個結果表中，稱為結果集。

-- id 列是自動更新的，表中的每條記錄都有一個唯一的數字。

-- 字串使用單引號(大部分數據庫系統也接受雙引號)
SELECT *
FROM Websites
WHERE country  =  "USA";
--
-- 數值不使用引號
SELECT *
FROM Websites
WHERE id  =  1;

-- mysql 中可以通過參數 sql_safe_updates 來限制
-- UPDATE/DELETE，防止全表更新或刪除。
-- SET sql_safe_updates = 1; -- 開啟該參數
--
-- 以下 3 種情況在採用此參數的情況下都不能正常進行操作：
-- 1 : 沒有加 WHERE 條件的全表更新操作；
-- 2 : 加了 WHERE 條件字段，但是 WHERE 字段沒有走索引的表更新；
-- 3 : 全表 DELETE 沒有加 WHERE 條件或者 WHERE 條件沒有走索引。

-- * --------------------------------------------------


-- * SELECT(選取)

-- 兩列
SELECT name_1, name_2
FROM table_name;

-- 全選
SELECT *
FROM table_name;


-- * --------------------------------------------------


-- * DISTINCT( == set )

SELECT DISTINCT country
FROM Websites;


-- * --------------------------------------------------


-- * WHERE( == if )

SELECT *
FROM Websites
WHERE country = 'CN';


-- * --------------------------------------------------


-- * ORDER BY(排序)

-- ASC 升序(預設)
SELECT *
FROM Websites
ORDER BY id ASC;

-- DESC 降序
SELECT *
FROM Websites
ORDER BY id DESC;

-- (升序), 降序
SELECT *
FROM Websites
ORDER BY country, id DESC;

-- * 欄位的順序
SELECT *
FROM Websites
ORDER BY 1;


-- * --------------------------------------------------


-- * LIKE(正則表達式)

SELECT *
FROM Websites
WHERE name LIKE '%G';

-- %(0 ~ 多個)
-- _(一個)
--
-- e.g.
-- A% : ABCDE == true,
-- A_ : AB == true, ABC == false


-- * --------------------------------------------------


-- * GROUP BY(聚合(合成))

SELECT Websites.name, COUNT(access_log.aid) AS nums
FROM access_log LEFT JOIN Websites ON access_log.site_id=Websites.id
GROUP BY Websites.name
HAVING SUM(access_log.count) > 200;


-- * --------------------------------------------------


-- * IN(多個值)

SELECT *
FROM Websites
WHERE name IN ('Google', '菜鸟教程');
-- equal
SELECT *
FROM Websites
WHERE name = 'Google' OR name = '菜鸟教程';


-- * --------------------------------------------------


-- * BETWEEN(範圍)

SELECT *
FROM Websites
WHERE name NOT BETWEEN 'A' AND 'H';


-- * --------------------------------------------------


-- * UPDATE(更新)

-- ! 沒有 WHERE 會導致整行都被更新
UPDATE Websites SET alexa = '5000', country = 'USA' WHERE name = '菜鸟教程';


-- * --------------------------------------------------


-- * DELETE(刪除), DROP, TRUNCATE

-- ! 沒有 WHERE 會導致全列表都被刪除
DELETE FROM Websites WHERE name = '百度' AND country = 'CN';

-- 执行速度  : DROP > TRUNCATE > DELETE
--
-- DELETE   : 删除表的内容，表的结构存在，　不释放空间，可以恢复
-- DROP     : 删除表内容和结构，　　　　　　　释放空间，没有备份表之前要慎用
-- TRUNCATE : 删除表的内容，表的结构存在，可以释放空间，没有备份表之前要慎用

-- 1、删除指定数据 : 删除表 test 中年龄等于 30 的且国家为 US 的数据
DELETE FROM test WHERE age=30 AND country='US';
-- 2、删除整个表 : 仅删除表 test 内的所有内容，保留表的定义，不释放空间。
DELETE * FROM test;

-- * DROP
DROP TABLE table_name;
DROP DATABASE database_name;
DROP INDEX Key_name ON tableName;
ALTER TABLE table_name DROP INDEX fk_name;

-- * --------------------------------------------------


-- * LIMIT x, ROWNUM (讀取 x 行資料)

-- SELECT TOP 5 FROM table_name;

SELECT *
FROM Websites
LIMIT
2;

SELECT *
FROM Persons
WHERE ROWNUM <= 5
ORDER BY column_name;

-- 百分比 // 前 50 %
SELECT TOP 50 PERCENT
    *
FROM Websites;


-- * --------------------------------------------------


-- * AS(命名, 別名)

SELECT
    name AS a,
    country AS b
FROM Websites;

SELECT
    w.name, w.url,
    a.count, a.date
FROM
    Websites   AS w,
    access_log AS a
WHERE a.site_id = w.id AND w.name = "菜鸟教程";

SELECT OrderYear, COUNT(DISTINCT CustomerID) AS NumCusts
FROM (SELECT YEAR(OrderDate), CustomerID
    FROM dbo.Orders) AS D(OrderYear, CustomerID)
GROUP BY OrderYear;