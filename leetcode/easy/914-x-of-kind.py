class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cards = {}
        
        if len(deck) < 2:
            return False
        
        for card in deck:
            if card not in cards:
                cards[card] = 1
            else:
                cards[card] += 1
                    
        return gcd(*list(cards.values())) >= 2
        
        
