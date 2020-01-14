-- * INSERT INTO(插入)

-- 无指定列名(全值)
INSERT INTO Websites
VALUES
    ('百度', 'https://www.baidu.com/', '4', 'CN');

-- 指定列名及被插入的值(無指定的值為 0)
INSERT INTO Websites
    (name, url, alexa, country)
VALUES
    ('百度', 'https://www.baidu.com/', '4', 'CN');


-- * --------------------------------------------------


-- * INSERT INTO SELECT(資料插入現有的表(表存在))

INSERT INTO Websites
    (name, country)
SELECT app_name, country
FROM apps;

-- * SELECT INTO(舊表資料複製到新表(表不存在) (列名是對應的，可用 AS 命名))

SELECT Websites.name, access_log.count, access_log.date
INTO WebsitesBackup2016
FROM Websites LEFT JOIN access_log ON Websites.id = access_log.site_id;


-- * --------------------------------------------------


-- * UNION(合併 不重複), UNION ALL(合併 重複)

    SELECT country, name
    FROM websites
    WHERE country = 'CN'
UNION ALL
    SELECT country, app_name
    FROM apps
    WHERE country='CN'
ORDER BY name;


-- * --------------------------------------------------


-- * JOIN ON(連接表)

-- INNER JOIN == and
--  LEFT JOIN == 左表架構，右表填入(不匹配 = NULL)
-- RIGHT JOIN == 右表架構，左表填入(不匹配 = NULL)
-- FULL OUTER JOIN = 左表架構 + 右表架構(不匹配 = NULL)

SELECT Websites.id, Websites.name, access_log.count, access_log.date
FROM Websites INNER JOIN access_log ON Websites.id = access_log.site_id;

SELECT *
FROM left_join RIGHT JOIN right_join ON access_log.site_id = Websites.id
ORDER BY access_log.count DESC;

SELECT Websites.name, access_log.count, access_log.date
FROM Websites FULL OUTER JOIN access_log ON Websites.id=access_log.site_id
ORDER BY access_log.count DESC;


-- * --------------------------------------------------


-- * CREATE INDEX(建立索引)
CREATE INDEX index_name ON table_name (column_name);


-- * --------------------------------------------------


-- * CREATE(建立)
-- * 约束(Constraints)

-- NOT NULL
-- NULL
-- UNIQUE                 ( == set )(可多個)
-- PRIMARY KEY            (主鍵)(不能包含 NULL)(只能一個)
-- FOREIGN KEY REFERENCES (指向另一個表中的 UNIQUE KEY)
-- CHECK                  (只允許特定的值)
-- DEFAULT                (插入默認值)
-- IDENTITY (1,1)         (開始, 遞增)

CREATE DATABASE my_db;

CREATE TABLE Persons
(
    P_Id      int          NOT NULL PRIMARY KEY ,
    LastName  varchar(255) NOT NULL IDENTITY (1,1),
    FirstName varchar(255),
    Address   varchar(255),
    City      varchar(255),
    UNIQUE(P_Id),
    -- 命名 UNIQUE 约束
    -- 定义多个列的 UNIQUE 约束
    CONSTRAINT uc_PersonID UNIQUE (P_Id, LastName),
    -- 主鍵
    CONSTRAINT PK_id PRIMARY KEY (P_Id),
    -- 指向另一個表中的 UNIQUE KEY
    CONSTRAINT fk_PerOrders FOREIGN KEY (P_Id) REFERENCES Persons (P_Id),
    -- CHECK(只允許特定的值)
    CONSTRAINT chk_Person CHECK (P_Id > 0 AND City = 'Sandnes'),
    -- DEFAULT(插入默認值)
    CONSTRAINT ab_c DEFAULT 'SANDNES' FOR City,
)

-- * ALTER(修改)

-- 修改類型
ALTER TABLE Persons
ALTER COLUMN DateOfBirth year

-- 列 附加
ALTER TABLE Persons
ADD CONSTRAINT uc_PersonID UNIQUE (P_Id,LastName)

-- 列 取消
ALTER TABLE Persons
DROP CONSTRAINT uc_PersonID