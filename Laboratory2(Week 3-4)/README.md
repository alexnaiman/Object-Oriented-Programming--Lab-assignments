# Laboratory assignment 3-4

### About this assignment


We had to implement a menu console based application with a given "theme" and set of functionalities
 


### Requirements (the exact problem statement)


>  ##### INTELLIGENT REFRIGERATOR
>  The company **“Home SmartApps”** has decided to design a new intelligent
refrigerator. Besides the hardware, they need a software application to
manage the refrigerator. Each Product has a name, a category (may be
dairy, sweets, meat or fruit), a quantity and an expiration date. 
> * The application must allow adding, deleting and updating a
product. A product is uniquely identified by name and category. If a
product that already exists is added, its quantity will be updated (the new
quantity is added to the existing one).
> * The application should offer the possibility to display all the
products whose names contain a given string (if the string is empty, all products from the
refrigerator are considered) and they will be shown sorted ascending by their quantities.
> * The application should be able to display all products of a given category (if the category is
empty, all types of food will be considered) whose expiration dates are close (expire in the
following given X days)
> * The application must provide multiple undo and redo functionality. Each step will undo/redo the
previous operation performed by the user.


> ##### Bonus possibility(which are also solved in the repo)
 >
> 1. Implement the following two extra requirements using function pointers (deadline:
week 4, bonus: 0.1p):
>   * For your problem, requirement b, add a different type of filtering (your choice).
>    * For your problem, requirement c, add descending sorting. The user should
choose the type of sorting and the program should show the list of entities
accordingly.
>
> 2. For iteration 2, provide 2 different implementations for the undo/redo functionality:
one using a list of operations (please see Seminar 2) and one using the “list of lists”
approach. Implement your dynamic array generically, such that it can contain any type
of elements (use void*). Use this structure for your repository, as well as to implement
the “list of lists” approach for the multiple undo/redo functionality (deadline: week 5,
bonus: 0.2p)
