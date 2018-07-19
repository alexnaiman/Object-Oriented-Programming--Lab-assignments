# Laboratory assignment 5-6

### About this assignment

For this assignment we had to add several features to our last project including:
 * "serialising" our data(storing it to a file of format CSV or HTML)
 * replacing our "normals for-s" with functions from STL(copy_if, find_if etc) and  with c++ 11 "foreach"-s
 * create custom exceptions for signaling errors
 
We also had a bonus point if we connect the project to an sql database management system. 
If you want to connect to your own mysql server search in the project for "REPLACE", then replace the variables with 
your own username and password.
 **To note:**
 For the html repository, because I was bored, I created a ReactJs web application which receives
 a Json as their data and then renders dynamicaly the tables for the repository and for the watchlist.
 
 For running the project run the command in the [html](./Lab4/Lab3-bun/html) folder for installing all our modules:
 
    npm install
    
 For running the project run the command:
 
    npm start
 
 After the project is started you can see the repository at [http://localhost:8000/](http://localhost:8000/watchlist)
 and the watchlist at [http://localhost:8000/watchlist](http://localhost:8000/watchlist)
 
You can read more about ReactJs and it's magic [here](https://reactjs.org/)
![Love React](https://www.techsophy.com/wp-content/uploads/2018/03/6-Reasons-why-we-love-ReactJS.png)

##### Prerequisites
 * [MySql C++ connector](https://dev.mysql.com/downloads/connector/cpp/8.0.html)
 
### Requirements (the exact problem statement)


> **For your assignment from Lab5-6, add the following features:**
> 1. Replace your DynamicVector template with the STL vector. Use STL algorithms wherever possible
in your application (e.g. in your filter function you could use copy_if, count_if). Replace all your
for loops either with STL algorithms, or with the ranged-based for loop (C++11).
> 2. Store your data in a text file. When the program starts, the entities in the database (file) will be
read. The modifications made during the execution of the application should be stored in the file.
For this feature, use the iostream library. Create insertion and extraction operators for your
entities and use these when reading/writing to files or console.
> 3. Use exceptions to signal errors:
>   - from the repository;
>   - validation errors – validate your entities using Validator classes;
>   - create your own exception classes.
>
>  Validate your input data
> 4.  Depending on your assignment, store your:
>    - adoption list
>    - movie watch list
>    - shopping basket
>    - tutorial watch list
>
>  in a file. When the application starts, the user should choose the type of file (CSV or HTML).
Depending on this type, the application should save the list in the correct format.
> 5. Add a new command, allowing the user to see the:
>   - adoption list
>   - movie watch list
>   - shopping basket
>   - tutorial watch list
>
> Displaying the list means opening the saved file (csv or html) with the correct application:
>   - CSV file – with Notepad, Notepad++, Microsoft Excel or OpenOffice Calc
>   - HTML file – with a browser
> 6. Create a UML diagram for your entire application. For this, you can use any tool that you like
(StarUML is an example of open source software for UML). Do not draw the diagram by hand.
