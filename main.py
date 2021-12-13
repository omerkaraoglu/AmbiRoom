from PIL import ImageGrab
import screen
import tcpclient

def list_mean(p):
    total = 0
    for t in p:
        total += t
    mean = total / len(p)
    return mean

while(1):
    R = [None] * screen.list_len
    G = [None] * screen.list_len
    B = [None] * screen.list_len

    for i in range(screen.list_len):
        px = ImageGrab.grab().load()
        flag = 0
        for y in range(0, screen.y, screen.gcd):
            for x in range(0, screen.x, screen.gcd):
                current_px = px[x, y]
                R[flag] = current_px[0]
                G[flag] = current_px[1]
                B[flag] = current_px[2]
                flag += 1

        #Ravr = list_mean(R)
        #Gavr = list_mean(G)
        #Bavr = list_mean(B)
        Ravr = sum(R) / len(R)
        Gavr = sum(G) / len(G)
        Bavr = sum(B) / len(B)

        tcpclient.sendRGB(int(Ravr), int(Gavr), int(Bavr))