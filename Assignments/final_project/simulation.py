8888888888 d8b                   888          8888888b.                   d8b                   888            
888        Y8P                   888          888   Y88b                  Y8P                   888            
888                              888          888    888                                        888            
8888888    888 88888b.   8888b.  888          888   d88P 888d888 .d88b.  8888  .d88b.   .d8888b 888888         
888        888 888 "88b     "88b 888          8888888P"  888P"  d88""88b "888 d8P  Y8b d88P"    888            
888        888 888  888 .d888888 888          888        888    888  888  888 88888888 888      888            
888        888 888  888 888  888 888          888        888    Y88..88P  888 Y8b.     Y88b.    Y88b.          
888        888 888  888 "Y888888 888 88888888 888        888     "Y88P"   888  "Y8888   "Y8888P  "Y888         
                                                                          888                                  
                                                                         d88P                                  
                                                                       888P"                                   
 .d8888b.  888              d8b                      d8888          888    888                                 
d88P  Y88b 888              Y8P                     d88888          888    888                                 
888    888 888                                     d88P888          888    888                                 
888        88888b.  888d888 888 .d8888b           d88P 888 88888b.  888888 88888b.   .d88b.  88888b.  888  888 
888        888 "88b 888P"   888 88K              d88P  888 888 "88b 888    888 "88b d88""88b 888 "88b 888  888 
888    888 888  888 888     888 "Y8888b.        d88P   888 888  888 888    888  888 888  888 888  888 888  888 
Y88b  d88P 888  888 888     888      X88       d8888888888 888  888 Y88b.  888  888 Y88..88P 888  888 Y88b 888 
 "Y8888P"  888  888 888     888  88888P'      d88P     888 888  888  "Y888 888  888  "Y88P"  888  888  "Y88888 
                                                                                                           888 
                                                                                                      Y8b d88P 
                                                                                                       "Y88P"  
# Import and initialize the pygame library
import pygame
import random
import math
from datetime import datetime
import json
import os

class simulation():
    def __init__(self):
        self.days = 1
        self.infected = 0
        self.deaths = 0
        self.maxdays = 50

    # daily advancement every 60 ticks
    def set_days(self):
        self.days += 1

    def runsim(self, model):

        # initialize pygame
        pygame.init()

        random.seed(datetime.now())
        # title of project
        pygame.display.set_caption('Covid19 Pandemic')

        # set up the drawing window
        screen = pygame.display.set_mode([Config["width"], Config["height"]])

        # sprites should be in a sprite group
        sprites_list = pygame.sprite.Group()

        # a list to hold all of our people sprites
        population = []

        # set font
        font = pygame.font.Font('./text/Roboto-Black.ttf', 20)

        # loop N times
        for i in range(Config["population_count"]):
            # add a "person" to our list of people
            # create an "instance" of our class
            population.append(Person(Config["width"], Config["height"], model.SIR[i],Config["sprite_width"],Config["sprite_height"],Config["sprite_speed"])) #random.choice(speeds)

            # Add last person to our sprites list
            # list[-1] give you the last item
            sprites_list.add(population[-1])  

        # setup the clock for a decent framerate
        clock = pygame.time.Clock() 
        seconds = 0

        # Run until the user asks to quit
        running = True

        ## this is our simulation object
        while running:

            # Did the user click the window close button?
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

                if event.type == pygame.MOUSEBUTTONUP:
                    pos = pygame.mouse.get_pos()
                    #print(pos)
                    population.append(Person(Config["width"], Config["height"], model.SIR[50],15,15,1,pos[0],pos[1])) #random.choice(speeds)

                    # Add last person to our sprites list
                    # list[-1] give you the last item
                    sprites_list.add(population[-1]) 


            # fill the background with blackish
            screen.fill((30, 30, 30))

            # loop through each person
            # and call a move method
            for i in range(len(population)):
                population[i].move()

            # determine collision
            for j in range(len(population)):
                if population[i] != population[j]:
                    collided = population[i].checkCollide(
                        population[j])
                    if collided:
                        dx, dy = population[i].getDxDy()
                        population[j].setDxDy(dx * -1, dy * -1)

            # determine the recovery status 
            for i in range(len(population)):
                population[i].recover(self.days)

            sprites_list.draw(screen)

            # infected count
            for i in range(len(population)):
                if population[i].state == "infected":
                    self.infected += 1

            # render text and place in a text box 
            text = font.render("Day " + str(self.days) + " Infected: " + str(self.infected) 
            + " Deaths: " + str(self.deaths), 
            True, (30, 255, 30), (30, 30, 255))
            textbox = text.get_rect()

            # setup textbox height and width
            textbox.right = Config["width"]
            textbox.bottom = Config["height"]

            # draw text on screen
            screen.blit(text, textbox)

            # update the display
            pygame.display.flip()

            # day advancement every 60 ticks
            if seconds % 60 == 0:
                self.set_days()

                # chances of death per day
                for i in range(len(population)):
                    if population[i].death() == True and population[i].state == "infected":
                        sprites_list.remove(population[i])
                        self.deaths += 1

            # ensure program maintains a rate of 40 frames per second
            clock.tick(40) 

            Config["myClock"] += 1
            seconds += 1
            self.infected = 0

            # stop the simulation if the maximum number of days are met
            if self.days > self.maxdays:
                running = False

# This class creates a person, provides them with an image and 
# allows them to react with their environment
class Person(pygame.sprite.Sprite):
    # Constructor for person
    def __init__(self,
                 screen_width,
                 screen_height,
                 SIR,
                 width=15,
                 height=15,
                 speed=1,inx=None,iny=None):

        # Call the parent class (Sprite) constructor
        super().__init__()

        self.id = Config["pid"]
        Config["pid"] +=1

        # screen width and height used to know
        # when to change direction at edge of screen
        self.screen_width = screen_width
        self.screen_height = screen_height

        # size of our sprite
        self.width = width
        self.height = height

        # direction x and direction y
        self.dx = 0
        self.dy = 0

        # ensure sprites movement
        while self.dx + self.dy == 0:
            self.dx = random.choice([1, -1, 0])
            self.dy = random.choice([1, -1, 0])

        # pixels per game loop
        #self.speed = random.choice([1,7])
        self.speed = speed
        self.original_speed = speed

        # set up a person's color based on their condition
        if SIR == "S":
            self.state = "susceptible" # any person who can catch the disease
            self.color = "yellow"
            self.dayinfected = -999

        elif SIR == "I":
            self.state = "infected" # a person that has the disease and is contagious
            self.color = "red"
            self.dayinfected = 1
        
        else:
            self.state = "recovered" # a person who had the disesase and recovered
            self.color = "green"
            self.dayinfected = -999

        # load image corresponding to a person's condition
        self.image = pygame.image.load(SIR_Model.SIR_images[self.color])
        
        # ensure picture is to correct scale
        self.image = pygame.transform.scale(self.image,
                                            (self.width, self.height))

        # Fetch the rectangle object that has the dimensions of the image.
        # Update the position of this object by setting the values
        # of rect.x and rect.y
        if inx is None:
            # creates a random location between bounds of screen size
            self.x = int(random.random() * self.screen_width)
        else:
            self.x = inx

        if iny is None:
            # creates a random location between bounds of screen size
            self.y = int(random.random() * self.screen_height)
        else:
            self.y = iny

        self.rect = self.image.get_rect(center=(self.x, self.y))

    # set a person's direction
    def setDxDy(self, dx, dy):
        self.dx = dx
        self.dy = dy

    # determine a person's direction
    def getDxDy(self):
        return (self.dx, self.dy)

    # direction change after collision
    def changeDirection(self, sides_contacted):
        if sides_contacted["top"]:
            self.dy = 1
        if sides_contacted["bottom"]:
            self.dy = -1
        if sides_contacted["left"]:
            self.dx = 1
        if sides_contacted["right"]:
            self.dx = -1

    # moves our sprite around the screen
    def move(self):

        sides_contacted = self.checkWalls()

        self.changeDirection(sides_contacted)

        if self.dx < 0:
            self.rect.x -= self.speed
        elif self.dx > 0:
            self.rect.x += self.speed

        if self.dy < 0:
            self.rect.y -= self.speed
        elif self.dy > 0:
            self.rect.y += self.speed

    # function which determines where a person is in relation to the other
    # and will return a boolean that determines whether a collision has occured.
    # The general direction the collision occured at will also be known.
    def checkCollide(self, other):
        sides_contacted = {
            "top": False,
            "bottom": False,
            "left": False,
            "right": False
        }

        if self.rect.colliderect(other.rect):

            if self.rect.top < other.rect.top:
                sides_contacted["bottom"] = True
                self.rect.y -= abs(self.rect.y - other.rect.y) // 8
            if self.rect.left < other.rect.left:
                sides_contacted["right"] = True
                self.rect.x -= abs(self.rect.x - other.rect.x) // 8
            if self.rect.right > other.rect.right:
                sides_contacted["left"] = True
                self.rect.x += abs(self.rect.x - other.rect.x) // 8
            if self.rect.bottom > other.rect.bottom:
                sides_contacted["top"] = True
                self.rect.y += abs(self.rect.y - other.rect.y) // 8
            
            infect_chance = random.randint(0, 100)

            # determine the probability of infection after contact
            if (infect_chance < virus.infection_rate and self.state == "susceptible" and 
            other.state == "infected"):
                self.state = "infected"
                self.color = "red"
                self.image = pygame.image.load(SIR_Model.SIR_images[self.color])
                self.image = pygame.transform.scale(self.image,(self.width, self.height))

            if (infect_chance < virus.infection_rate and other.state == "susceptible" and 
            self.state == "infected"):
                other.state = "infected"
                other.color = "red"
                other.image = pygame.image.load(SIR_Model.SIR_images[other.color])
                other.image = pygame.transform.scale(other.image,(other.width, other.height))

            self.changeDirection(sides_contacted) 

            return True

        return False

    # This function ensures that the sprites stay within the screen's borders
    def checkWalls(self):
        sides = {"top": False, "bottom": False, "left": False, "right": False}

        if self.rect.top <= 0:
            sides["top"] = True
        if self.rect.left <= 0:
            sides["left"] = True
        if self.rect.right >= self.screen_width:
            sides["right"] = True
        if self.rect.bottom >= self.screen_height:
            sides["bottom"] = True

        return sides
    
    # the probability of a person's death after being infected for
    # for a period of time is randomly determined. If death occurs
    # they are removed from the screen 
    def death(self):
        dead = False
        die_chance = random.randint(0, 100)

        if die_chance < virus.fatality_rate and self.state == "infected":
            dead = True

        return dead

    # a person will eventually recover after being infected for a certain period of time
    def recover(self, day):
        if day - self.dayinfected > virus.days_infected:
            self.state = "recovered"
            self.image = pygame.image.load(SIR_Model.SIR_images["green"])
            self.image = pygame.transform.scale(self.image,
                                                (self.width, self.height))
            

# Class for SIR model creation
class SIR_Model():
    # This isn't part of an constructed object, but is here for organization ++++++++++++
    SIR_images = {
        "red" :  "./images/person_red.png",
        "green":  "./images/person_green.png",
        "yellow":  "./images/person_yellow.png",
    }

    def __init__(self):
        self.SIR = []
        self.susceptible_prob = .70
        self.recovered_prob = .10
        self.initial_infect = .20
    
    def make_model(self):

        S = ["S"] * int(self.susceptible_prob * 100)
        I = ["I"] * int(self.initial_infect * 100)
        R = ["R"] * int(self.recovered_prob * 100)

        self.SIR = S + I + R

        random.shuffle(self.SIR)

# input data from a json file into a dictionary
if os.path.isfile("config.json"):

    f = open("config.json", "r")
    data = f.read()
    Config = json.loads(data)

# The virus class deals with the infection rate, fatality rate and days infected.
class virus():
    infection_rate = 80 # probability of infection
    fatality_rate = 5 # out of 100%
    days_infected = 14 # days infected count
#__________________________________________________________________________
if __name__=='__main__':

    # Create instances of sim and model classes
    sim = simulation()
    model = SIR_Model()

    model.make_model() 
    
    # Run Covid19 Pandemic Simulation
    sim.runsim(model) 

    # Done! Time to quit.
    pygame.quit()
