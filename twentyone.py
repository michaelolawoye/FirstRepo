import random
import time


class Game:
    TARGET = 21
    SUITS = {0: "Clubs",
             1: "Hearts",
             2: "Spades",
             3: "Diamonds"}

    def __init__(self) -> None:
        self._playervalue = 0
        self._computervalue = 0
        self._playercards = [[], [], [], []] # [Clubs, Hearts, Spades, Diamonds]
        self._computercards = [[], [], [], []] # Same as above

    @staticmethod
    def random_card():
        card_num = random.randint(1, 11) # Random number range represents number and face cards
        suit = random.randint(0, 3) # Random number range represents suits 0 = Clubs, 1 = Hearts, 2 = Spades, 3 = Diamonds
        return card_num, suit

    def _show_hands(self) -> None:
        print("Current hand:")

#       Computer's hand
        print("I have: ")

        for current_suit, _ in enumerate(self._computercards):
            for num in self._computercards[current_suit]:
                if num == 1 or 11:
                    print(f"Ace of {Game.SUITS[current_suit]}, ",)
                else:
                    print(f"{num} of {Game.SUITS[current_suit]}, ")

#       Player's hand
        print("You have: ")

        for current_suit, _ in enumerate(self._playercards):
            for num in self._playercards[current_suit]:
                if num == 1 or num == 11:
                    print(f"The Ace of {Game.SUITS[current_suit]}")
                else:
                    print(f"The {num} of {Game.SUITS[current_suit]}")

    def _draw(self, player=True):
        card = self.random_card()
        if player:
            self._playercards[card[1]].append(card[0])
        else:
            self._computercards[card[1]].append(card[0])

    def _calculate_value(self, player=True):

        if player:
            for i, _ in enumerate(self._playercards):
                for num in self._playercards[i]:
                    self._playervalue += num
        else:
            for i, _ in enumerate(self._computercards):
                for num in self._computercards[i]:
                    self._computervalue += num

    def _clear_hands(self):
        for i, _ in enumerate(self._playercards):
            self._playercards[i].clear()
        for i, _ in enumerate(self._computercards):
            self._computercards[i].clear()
        self._playervalue = 0
        self._computercards = 0

    def play(self):
        self._clear_hands()
        print("Let's start.")
        time.sleep(0.5)
        self._draw()
        self._draw()
        self._draw(False)

        while True:
            self._show_hands()
            self._calculate_value()
            self._calculate_value(False)

            if self._playervalue == Game.TARGET and self._computervalue == Game.TARGET:
                print("It's a tie!")
                break
            elif self._playervalue == Game.TARGET:
                print("You win!")
                break
            elif self._computervalue == Game.TARGET:
                print("Blackjack! I win")
                break
            elif self._computervalue < 17:
                print("I'm drawing a card.")
                self._draw(False)
                self._computervalue = self._calculate_value(False)
            else:
               again = input(f"You have {self._playervalue} points, would you like to draw a card? (y/n): ")
               if again == 'y':
                   continue
               elif again == 'n':
                   break

g = Game()

