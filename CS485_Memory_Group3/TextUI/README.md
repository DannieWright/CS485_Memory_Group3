## TextUI Documentation


### TextUI

The main UI loop and TextUI interface. Subclass this class.  Use addWidget() to add a widget to the screen.  Use registerEvent() to register UI events to be handled.

---

```
void UIEventLoop ();
```
Invoke to start the UI Loop. The loop will draw the widgets on the screen then present a UI Event menu.  The user selects an event from the menu and specifies an argument to that event.  Ths event is then dispatched to the correct event handler.

---

```
void registerEvent(std::string name, std::function<void(std::string)> func);
```

Register an event with the event menu with the given name and cause the func to be invoked when that event happens.  The string parameter to func is the argument given to the event menu.



### ITextUIWidget

Abstract parent class for all UI Widgets on the screen.

```
virtual void draw(std::ostream &) = 0;
```
override in child class to draw the widget 

---


### TextUITextWidget

A basic text widget. The text is displayed on the screen as:
```
Label: Data
```
or, if there is no label:
```
Data
```
---

```
void setData(string);
string getData(string);
```
Access the string data displayed in the Widget.

---

```
void setLabel(string);
string getLabel(string);
```
Access the label data displayed in the Widget.


