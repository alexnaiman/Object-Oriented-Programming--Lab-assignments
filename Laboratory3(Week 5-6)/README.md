# Laboratory assignment 5-6

### About this assignment


We had to implement a menu console based application with a given "theme" and set of functionalities

Test coverage should be at least 98% for all layers, except UI.

 * For the first iteration we should solve at least the requirements related to the administrator
mode. You should define a user defined type DynamicVector, which provides
the specific operations: add, remove, length, etc. The array of elements in the
DynamicVector must be dynamically allocated

 * For the second iteration Iteration 2 should solve all problem requirements. The DynamicVector should be
modified to use templates. 

#####Prerequisites
 * [OpenCppCoverage Plugin](https://marketplace.visualstudio.com/items?itemName=OpenCppCoverage.OpenCppCoveragePlugin)

### Requirements (the exact problem statement)


>  #####MASTER C++
> You are very passionate about programing (otherwise you wouldn’t be here, reading this) and C++ is a
language so close to your heart. On your way to becoming a C++ guru, you study a lot and watch many
tutorials. To make sure you do not miss any good tutorials, you absolutely need a software application
to help you manage your tutorials and create watch lists. The application can be used in two modes:
administrator and user. When the application is started, it will offer the option to choose the mode.
>
>**Administrator mode**: The application will have a database, which holds all the tutorials. You must be
able to update the database, meaning: add a new tutorial, delete a tutorial and update the information
of a tutorial. Each Tutorial has a title, a presenter (name of the presenter person), a duration (minutes
and seconds), a number of likes and a link towards the online resource containing the tutorial. The
administrators will also have the option to see all the tutorials in the database
>
> **User mode**: A user can create a watch list with the tutorials that he/she wants to watch. The application
will allow the user to:
> * See the tutorials in the database having a given presenter (if the presenter name is empty,
see all the tutorials), one by one. When the user chooses this option, the data of the first
tutorial (title, presenter, duration, number of likes) is displayed and the tutorial is played in
the browser.
> * If the user likes the tutorial, he/she can choose to add it to his/her tutorial watch list.
> * If the tutorial seems uninteresting, the user can choose not to add it to the watch list and
continue to the next. In this case, the information corresponding to the next tutorial is
shown and the user is again offered the possibility to add it to the watch list. This can
continue as long as the user wants, as when arriving to the end of the list of tutorials with
the given presenter, if the user chooses next, the application will again show the first
tutorial.
> * Delete a tutorial from the watch list, after the user watched the tutorial. When deleting a
tutorial from the watch list, the user can also rate the tutorial (with a like), and in this case,
the likes of the tutorials in the repository will be increased.
> * See the watch list.
