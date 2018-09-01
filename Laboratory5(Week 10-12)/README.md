# Laboratory assignment 8-10 + 14 

### About this assignment

Here I combined both of my assignments: the one with the GUI and the one with the Model View architecture 

**Lab 8-9(10-11)**

For this assignment we had to add GUI to our app with the Qt framework

For the first iteration, we could not use the Qt Designer, but for the second iteration we were allowed to use it.
That's the reason for having two project directories 
 
We also had a bonus point if we create a graphic representation for our data.

**Lab 14**

For this assignment we had to add another window that used the Qt Model-View architecture

I used that architecture from the beginning, so I didn't have to add anything about that  to the project

We also had to add multiple undo and redo functionality 

##### Prerequisites
 * [Qt Framework](https://www.qt.io/)
 * [QCustomPlot](https://www.qcustomplot.com/)
 
### Requirements (the exact problem statement)

> ## Laboratory 10-12
> **Create a graphical user interface (GUI) for the problem you have been working on (Labs 5,6,7,8),
using Qt**
> * For the first iteration, due in Week 11, you should implement at least the design of the interface
and the list/table displaying the repository entities (administrator mode) should be populated.
> * For the first iteration, the GUI must be created and coded manually (no Qt Designer!).
> * For the second iteration, due in Week 12, all the required functionalities should be available using
the GUI. For this iteration, you may use Qt Designer, if you want to change the initial design of
your GUI.
> * The functionality of the application must be the same (including the one-by-one iteration of
objects for the user mode).

>  **ADDITIONAL REQUIREMENT - BONUS POSSIBILITY (0.2 P)**
>
>  Create a graphic representation of the data in your application. You have an example below: a bar chart
representing the number of songs for each artist. Your representations can be a bar chart, a pie chart or
another type of chart. You can even use circles or rectangles or any other geometric shapes to “draw”
your data. To receive the bonus, the requirements must be implemented correctly, by week 12 and the
application must function properly
> ## Laboratory 14
> 1. Add a multiple undo and redo functionality for the operations “add”, “remove”, “update” in
your repository. Implement this functionality using inheritance and polymorphism. You will
have an “Undo” and “Redo” buttons on your GUI, or a key combination to undo and redo
the operations (e.g. Ctrl+Z, Ctrl+Y).
> 2. Create a new window which presents the contents of your:
>    - adoption list
>   - movie watch list
>    - shopping basket
>   - tutorial watch list
> 
> This window will contain a list view/table view with all the elements in your list. You must use Qt
View/Model components (QListView/QTableView). Create your own model – a class which
inherits from QAbstractListModel or QAbstractTableModel.
>
> This window will be opened from your GUI main window
>
> **ADDITIONAL REQUIREMENT - BONUS POSSIBILITY (0.2 P)**
>
> For each of the requirements below, you can get 0.1 bonus points.
> 1. Add a multiple undo and redo functionality for your adoption list/movie watch list/shopping
basket/tutorial watch list. We have to be able to test it using your GUI application.
> 2. Use custom delegates in Qt. In one of the columns of the Qt table view that shows the elements
in your adoption list/movie watch list/shopping basket/tutorial watch list, display an image of the
dog/trench coat (for problems 1 and 3), or a play button (for problems 2 and 4) – which can play
the movie trailer or the tutorial. Please see two examples on the following page.