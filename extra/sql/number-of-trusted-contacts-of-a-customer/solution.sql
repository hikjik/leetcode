SELECT Invoices.invoice_id, Customers.customer_name, Invoices.price, 
       COUNT(DISTINCT Contacts.contact_name) AS contacts_cnt, 
       COUNT(DISTINCT Trusted.customer_name) AS trusted_contacts_cnt 
  FROM Invoices
  LEFT JOIN Customers
    ON Invoices.user_id = Customers.customer_id 
  LEFT JOIN Contacts
    ON Contacts.user_id = Customers.customer_id 
  LEFT JOIN Customers Trusted
    ON Trusted.customer_name = Contacts.contact_name 
 GROUP BY Invoices.invoice_id
 ORDER BY Invoices.invoice_id;
