import pygame
import sys
import random

# Init Pygame
pygame.init()

# Setup Layar
width = 800
height = 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Plane Evasion - Power Up Edition")

# Font
font = pygame.font.SysFont('arial', 32)
game_over_font = pygame.font.SysFont('arial', 48)

# Warna
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
GOLD = (255, 215, 0)
PURPLE = (128, 0, 128)

# --- LOAD ASSETS ---
def load_and_scale(path, size):
    try:
        img = pygame.image.load(path).convert_alpha()
        return pygame.transform.scale(img, size)
    except:
        # Jika gambar tidak ada, buat kotak warna sebagai pengganti
        surf = pygame.Surface(size)
        surf.fill(GOLD)
        return surf

player_image = load_and_scale('pesawat_karakter.png', (60, 60))

#Mengganti gambar item
bomb_image = load_and_scale('icon_bomb.png', (40, 40)) 
shield_image = load_and_scale('icon_shield.png', (40, 40))

class Character:
    def __init__(self, x, y, w, h):
        self.x = x
        self.y = y
        self.width = w
        self.height = h

    def get_rect(self):
        return pygame.Rect(self.x, self.y, self.width, self.height)

class Player(Character):
    def __init__(self, x, y):
        super().__init__(x, y, 60, 60)
        self.speed = 7
        self.is_invincible = False
        self.invincible_timer = 0

    def draw(self, surface):
        # Beri efek visual jika sedang kebal (shield)
        if self.is_invincible:
            pygame.draw.circle(surface, (0, 255, 255), (self.x + 30, self.y + 30), 40, 3)
        surface.blit(player_image, (self.x, self.y))

    def move(self, keys):
        if keys[pygame.K_LEFT] and self.x > 0: self.x -= self.speed
        if keys[pygame.K_RIGHT] and self.x < width - self.width: self.x += self.speed
        if keys[pygame.K_UP] and self.y > 0: self.y -= self.speed
        if keys[pygame.K_DOWN] and self.y < height - self.height: self.y += self.speed

class Enemy(Character):
    def __init__(self, x, y):
        super().__init__(x, y, 40, 40)
        self.speed = random.randint(4, 7)

    def update(self):
        self.y += self.speed

    def draw(self, surface):
        pygame.draw.rect(surface, RED, self.get_rect())

class Item(Character):
    def __init__(self, x, y, type):
        super().__init__(x, y, 40, 40)
        self.type = type # "BOMB" atau "SHIELD"
        self.speed = 4

    def update(self):
        self.y += self.speed

    def draw(self, surface):
        if self.type == "BOMB":
            surface.blit(bomb_image, (self.x, self.y))
        else:
            surface.blit(shield_image, (self.x, self.y))

# Inisialisasi
player = Player(width // 2, height - 80)
enemies = []
items = []
spawn_timer = 0
item_timer = 0
is_game_over = False
clock = pygame.time.Clock()

# --- MAIN LOOP ---
while True:
    screen.fill(WHITE)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    if not is_game_over:
        keys = pygame.key.get_pressed()
        player.move(keys)

        # Update Invincibility Timer (Shield)
        if player.is_invincible:
            player.invincible_timer -= 1
            if player.invincible_timer <= 0:
                player.is_invincible = False

        # 1. Spawn Musuh
        spawn_timer += 1
        if spawn_timer > 30:
            enemies.append(Enemy(random.randint(0, width-40), -50))
            spawn_timer = 0

        # 2. Spawn Item (Lebih jarang muncul)
        item_timer += 1
        if item_timer > 200: # Muncul setiap ~3-4 detik
            itype = random.choice(["BOMB", "SHIELD"])
            items.append(Item(random.randint(0, width-40), -50, itype))
            item_timer = 0

        # 3. Logika Item
        for item in items[:]:
            item.update()
            item.draw(screen)
            if item.get_rect().colliderect(player.get_rect()):
                if item.type == "BOMB":
                    enemies.clear() # Kosongkan semua musuh
                elif item.type == "SHIELD":
                    player.is_invincible = True
                    player.invincible_timer = 5 * 60 # 5 detik (FPS=60)
                items.remove(item)
            elif item.y > height:
                items.remove(item)

        # 4. Logika Musuh
        for enemy in enemies[:]:
            enemy.update()
            enemy.draw(screen)
            
            if enemy.get_rect().colliderect(player.get_rect()):
                if not player.is_invincible:
                    is_game_over = True
            #logika untuk fitur clean up
            if enemy.y > height:
                enemies.remove(enemy)

        player.draw(screen)
        
        # Tampilkan status Shield jika aktif
        if player.is_invincible:
            timer_text = font.render(f"SHIELD: {player.invincible_timer // 60 + 1}s", True, BLUE)
            screen.blit(timer_text, (10, 10))

    else:
        # Game Over Screen
        go_surf = game_over_font.render("GAME OVER", True, RED)
        screen.blit(go_surf, (width // 2 - 120, height // 2 - 50))

    pygame.display.update()
    clock.tick(60)