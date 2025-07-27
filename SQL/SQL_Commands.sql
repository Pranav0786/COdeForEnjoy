select * from employees ;

select * from employees where department = 'HR';

select name , salary from employees where salary between 50000 and 100000;

select * from employees where department = 'IT' and salary > 60000;
select * from employees where department in ('Finance', 'Marketing');
select * from employees where department not in  ( 'HR', 'IT');
select * from employees where pincode = NULL;


--  % => any number of characters
--  _ => single character

-- Wildcard search
select * from employees where name like 'V%' ; 
select * from employees where name like '_e%ka' ;


-- sorting 
select * from employees order by salary ;
select * from employees order by department, salary desc;

-- distinct values
select distinct department from employees;


-- grouping and aggregation
select department count(*) from employees group by department;
select department , avg(salary) as average_salary from employees group by department;

-- having clause
select department , count(*) from employees group by department having count(*) > 2 ;



-- add new col
alter table employees add column interview_date date ;

-- modify
alter table employees modify column interview_date datetime;


-- rename column    
                                    -- old name       -- new name
alter table employees change column interview_date interview_datetime datetime;


-- drop column
alter table employees drop column interview_datetime ;
-- rename table
            -- old name       -- new name
alter table employees rename to staff;



-- DML deta modification language
insert into employees (name, department, salary, pincode) values ('John Doe', 'HR', 75000, '123456');

-- update => only updates the rows that match the condition
update employees set salary = 80000 where name = 'John Doe';

-- delete
delete from employees where name = 'John Doe' ;

-- on delete cascade => if a row in the parent table is deleted, all related rows in the child table are also deleted.
delete from employees where department = 'HR' on delete cascade ;
-- on delete set null => if a row in the parent table is deleted, all related rows in the child table have their foreign key set to NULL.

-- replace into => used to replace a row in a table with new values or insert a new row if it does not exist.
replace into employees (name, department, salary, pincode) values ('Jane Smith', 'Finance', 90000, '654321');



-- Joins
-- there must be a common column in both tables to join them
-- (1) INNER JOIN => returns only the rows that have matching values in both tables
select c.* , o.* from customers as c INNER JOIN orders as o on c.customer_id = o.customer_id ;
-- (2) Outer Join => returns all rows from both tables, with NULLs in place where there is no match
-- (2.1) LEFT JOIN => returns all rows from the left table and matching rows from the right table
select c.* , o.* from customers as c LEFT JOIN orders as o on c.customer_id = o.customer_id ;
-- (2.2) RIGHT JOIN => returns all rows from the right table and matching rows from the left table
select c.* , o.* from customers as c RIGHT JOIN orders as o on c.customer_id = o.customer_id ;
-- (2.3) FULL OUTER JOIN => returns all rows from both tables, with NULLs in place where there is no match
select c.* , o.* from customers as c FULL OUTER JOIN orders as o on c.customer_id = o.customer_id ;



-- Union , intersection, difference
-- (1) UNION => combines the result sets of two or more SELECT statements, removing duplicates
select name from employees where department = 'HR'
union
select name from employees where department = 'Finance';
-- (2) UNION ALL => combines the result sets of two or more SELECT statements, including duplicates
select name from employees where department = 'HR'
union all
select name from employees where department = 'Finance';
-- (3) INTERSECT => returns the rows that are common to all SELECT statements
select name from employees where department = 'HR'
intersect
select name from employees where department = 'Finance';
-- (4) EXCEPT => returns the rows that are in the first SELECT statement but not in any of the other SELECT statements
select name from employees where department = 'HR'
except
select name from employees where department = 'Finance';



-- sub queries
-- 3rd largets salary
select distinct e1.salary from employees e1 where 3 = ( select count( distinct e2.salary) from employees e2 where e2.salary >= e1.salary ) ;


-- views
create view high_salary_employees as
select * from employees where salary > 80000 ; 














-- questions
-- q9 Replace all occurrences of 'a' with 'A' in first_name
SELECT REPLACE(first_name, 'a', 'A') FROM workers;

-- q10 Display full name by combining first_name and last_name
SELECT CONCAT(first_name, ' ', last_name) AS full_name FROM workers;

-- q11 Display all workers sorted by first_name
SELECT * FROM workers ORDER BY first_name;

-- q12 Display all workers sorted by first_name ascending and department descending
SELECT * FROM workers ORDER BY first_name ASC, department DESC;

-- q13 Display workers whose first_name is either 'Vipul' or 'Satish'
SELECT * FROM workers WHERE first_name IN ('Vipul', 'Satish');

-- q14 Display workers whose first_name is not 'Vipul' or 'Satish'
SELECT * FROM workers WHERE first_name NOT IN ('Vipul', 'Satish');

-- q15 Display workers whose department starts with 'admin'
SELECT * FROM workers WHERE department LIKE 'admin%';

-- q16 Display workers whose first_name contains the letter 'a'
SELECT * FROM workers WHERE first_name LIKE '%a%';

-- q17 Display workers whose first_name ends with 'a'
SELECT * FROM workers WHERE first_name LIKE '%a';

-- q18 Display workers whose first_name ends with 'h' and has length 6
SELECT * FROM workers WHERE first_name LIKE '%h' AND LENGTH(first_name) = 6;

-- q19 Display workers with salary between 100000 and 500000
SELECT * FROM workers WHERE salary BETWEEN 100000 AND 500000;

-- q20 Display workers who joined in February 2014
SELECT * FROM workers WHERE YEAR(joining_date) = 2014 AND MONTH(joining_date) = 02;

-- q21 Count number of workers in 'admin' department
SELECT department, COUNT(*) FROM workers WHERE department = 'admin';

-- q22 Display first and last names of workers with salary between 50000 and 100000
SELECT first_name, last_name FROM workers WHERE salary BETWEEN 50000 AND 100000;

-- q23 Display departments and their worker counts, ordered by count descending
SELECT department, COUNT(*) FROM workers GROUP BY department ORDER BY COUNT(*) DESC;

-- q24 Display all worker details who have the title 'Manager'
SELECT w.* FROM workers w INNER JOIN title t ON w.worker_id = t.worker_ref_id WHERE t.title = 'Manager';

-- q25 Display worker_title and count of each title with count > 1
SELECT worker_title, COUNT(*) AS number_of_workers FROM title GROUP BY worker_title HAVING COUNT(*) > 1;

-- q26 Display all workers with odd worker_id
SELECT * FROM workers WHERE MOD(worker_id, 2) != 0;

-- q27 Display all workers with even worker_id
SELECT * FROM workers WHERE MOD(worker_id, 2) = 0;

-- q28 Clone the workers table and display data from the cloned table
CREATE TABLE worker_clone LIKE workers;
INSERT INTO worker_clone SELECT * FROM workers;
SELECT * FROM worker_clone;

-- q29 Display workers that exist in both workers and worker_clone
SELECT workers.* FROM workers INNER JOIN worker_clone USING(worker_id);

-- q30 Display workers that exist in workers but not in worker_clone
SELECT workers.* FROM workers LEFT JOIN worker_clone USING(worker_id) WHERE worker_clone.worker_id IS NULL;

-- q31 Display current date and timestamp
SELECT CURDATE(); 
SELECT NOW();

-- q32 Display top 5 highest paid workers
SELECT * FROM workers ORDER BY salary DESC LIMIT 5;

-- q33 Display the 5th highest paid worker
SELECT * FROM workers ORDER BY salary DESC LIMIT 4,1;

-- q34 Display the worker with the 5th highest distinct salary
SELECT * FROM workers w1 WHERE 4 = (SELECT COUNT(DISTINCT w2.salary) FROM workers w2 WHERE w2.salary > w1.salary);

-- q35 Display workers who share the same salary with others
SELECT w1.* FROM workers w1, workers w2 WHERE w1.salary = w2.salary AND w1.worker_id != w2.worker_id;

-- q36 Display the second highest salary using three different methods
SELECT salary FROM workers ORDER BY salary DESC LIMIT 1,1;
SELECT salary FROM workers w1 WHERE 1 = (SELECT COUNT(DISTINCT w2.salary) FROM workers w2 WHERE w2.salary > w1.salary);
SELECT MAX(salary) FROM workers WHERE salary NOT IN (SELECT MAX(salary) FROM workers);

-- q37 Display all workers twice using UNION ALL
SELECT * FROM workers UNION ALL SELECT * FROM workers ORDER BY worker_id;

-- q38 Display worker_ids that don’t exist in bonus table
SELECT worker_id FROM workers WHERE worker_id NOT IN (SELECT worker_ref_id FROM bonus);

-- q39 Display first half of workers based on worker_id count
SELECT * FROM workers WHERE worker_id <= (SELECT COUNT(worker_id)/2 FROM workers);

-- q40 Display departments with less than 4 workers
SELECT department, COUNT(department) AS depcount FROM workers GROUP BY department HAVING depcount < 4;

-- q41 Display worker count in each department
SELECT department, COUNT(department) AS depcount FROM workers GROUP BY department;

-- q42 Display details of the worker with the maximum worker_id
SELECT * FROM workers WHERE worker_id = (SELECT MAX(worker_id) FROM workers);

-- q43 Display details of the worker with the minimum worker_id
SELECT * FROM workers WHERE worker_id = (SELECT MIN(worker_id) FROM workers);

-- q44 Display last 5 workers (by ID) in ascending order
(SELECT * FROM workers ORDER BY worker_id DESC LIMIT 5) ORDER BY worker_id;

-- q45 Display highest paid worker from each department
SELECT w.department, w.first_name, w.salary 
FROM (SELECT MAX(salary) AS salary, department FROM workers GROUP BY department) temp 
INNER JOIN workers w ON w.salary = temp.salary AND w.department = temp.department;

-- q46 Display top 3 distinct salaries in descending order
SELECT DISTINCT salary FROM workers w1 
WHERE 3 >= (SELECT COUNT(DISTINCT salary) FROM workers w2 WHERE w2.salary > w1.salary) 
ORDER BY w1.salary DESC;

-- q47 Display bottom 3 distinct salaries in ascending order
SELECT DISTINCT salary FROM workers w1 
WHERE 3 >= (SELECT COUNT(DISTINCT salary) FROM workers w2 WHERE w2.salary < w1.salary) 
ORDER BY w1.salary;

-- q48 Display top n salaries (replace n with a number as needed)
SELECT DISTINCT salary FROM workers w1 
WHERE n >= (SELECT COUNT(DISTINCT salary) FROM workers w2 WHERE w2.salary > w1.salary) 
ORDER BY w1.salary;

-- q49 Display total salary per department
SELECT department, SUM(salary) AS depSal FROM workers GROUP BY department;

-- q50 Display names of workers with the highest salary
SELECT first_name, salary FROM workers WHERE salary = (SELECT MAX(salary) FROM workers);


-- remove reversed pairs
-- Method 1 JOINS
select p1.* from pairs p1 left join pairs p2 on p1.first = p2.second and p1.second = p2.first 
where p2.first is NULL or p1.first < p2.first ;
-- Method 2 Co-related
select * from pairs p1 where not exists 
( select * from pairs p2 where p1.first = p2.second and p1.second = p2.first ans p1.first > p2.first ) ;



