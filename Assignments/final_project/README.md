# COVID-19 Pandemic Simulation

### *Instructions for running the simulation:* 

Open the main folder in Vscode or any text editor/IDE that you are using that can run python. Be advised that these instructions assumes that youare running vscode. To begin the simulation, right click anywhere within the code and select run python file in terminal. If no errors are found the simulation should run.

## *Altering the simulation:*

In order to make changes to the simulation in terms of how it runs, this can be done by altering the values in config.json. Please note that the keys (example: "width") should not be changed, only the values following them.


## *Description of the simulation:*

This program simulates the effects of a typical viral outbreak, in this case Covid-19, on a population of people. The ultimate goal is to get a visualization of how a disease spreads and so the SIR model will be used to demonstrate this. The SIR models the flows of people between three states: susceptible(S) or vulnerable, infected(I) and resistantnor recovered(R). People are randomly assigned to either be susceptible/vulnerable, infected or recovered. Contact between people is also modeled to be random. Vulnerable people may become infected by the virus or remain susceptible to it, while infected people may either die or recover from it, whereas people who recover from the virus become immune to it. The virus is primarily spread between people during close contact, thus persons who are infected who come into contact with a susceptible person will become infected as well. A certain number of processor "ticks" will represent each simulation day. The simulation runs for  a period of 50 days. Various information will be displayed on screen such as the
number of people who are infected, recovered and have died from the virus. The simulation can be terminated by a simple click of the x button in the game window. 

### Classes:  

## *Simulation Class:*

This class basically drives the entire program and interacts with pygame. Objects are created for every other class in the program and uses them as data in the simulation. A list of people who belong to the population is created when the simulation begins. A random number of persons with varying conditions will fill this list. Following this, the class will begin moving people around, thus simulating the outbreak. The simulation values will also be applied which will determine how the virus spreads. The number of days will be monitored by the simulation class and will terminate the simulation when the maximum number of days is reached.
   
## *Person Class:*

All information regarding a person will be stored in this class. Sprites will be used to represent individuals and an image will also be assigned to each person depending on their condition. This class will be utilizing various methods such as determining an individual's movement, setting up a person's image based on their condition, detecting if a collision is made, ensuring that a person remains within the boundaries and determining if an infected person will either die or not. These functions are in constant use by the simulation class for the runnings of the program. 

## *SIR Class:*

This class is basically used to randomly create a model of the outbreak. The initial conditions of the virus in the population will be determined by the SIR model. 

## *Virus Class:*

This class contains information regarding the virus such as the fatality rate, infection rate and days infected.




