USE Instrument_shop;

INSERT INTO CUSTOMERS (customer_name, customer_surname, customer_phone, customer_email)
VALUES ('Konstantin', 'Skabort', '+79169392741', 'kostas-96@ya.ru');
INSERT INTO PRODUCTS (weight, price, manufacturer, model, engine, description, type_of_work, work_material)
VALUES ('1049', '9690', 'Bosch', 'GSR 18-2-LI', 'brusherest', 'Cordless Drill Screwdriver', 'Installation work', 'Universally');

ALTER TABLE placement MODIFY COLUMN product_id INT(10) NOT NULL DEFAULT '1';
ALTER TABLE orders MODIFY COLUMN customer_id INT(10) NOT NULL DEFAULT '1';
ALTER TABLE order_item MODIFY COLUMN order_num INT(10) NOT NULL DEFAULT '1';
ALTER TABLE order_item MODIFY COLUMN product_id INT(10) NOT NULL DEFAULT '1';

INSERT INTO `PLACEMENT` (`placement_id`, `placement_row`, `subway`) VALUES ('1045','B','Lenensky prospect');
INSERT INTO `instrument_shop`.`orders` (`order_date`) VALUES ('2017-03-20');
INSERT INTO `instrument_shop`.`order_item` (`quantity`) VALUES ('3');

SELECT customers.customer_id, order_id, customer_name, customer_surname, order_date
FROM
orders, customers
WHERE
orders.customer_id = customers.customer_id;

SELECT orders.customer_id, customer_name, customer_surname, products.description, products.model
FROM
orders, order_item, customers, products
WHERE
orders.order_id  = '1' AND orders.order_id = order_item.order_num AND products.id = order_item.product_id;

SELECT
products.description, products.model, placement_row, placement_id, subway
FROM
products, placement
WHERE
placement.product_id = products.id;

SELECT id, weight, price, manufacturer, model, products.engine, description, type_of_work, work_material, placement.placement_id, placement.placement_row, subway
FROM products, placement
WHERE products.id = placement.placement_id;