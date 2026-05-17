from sys import stdin
from heapq import heappush, heappop

# direcciones basicas
DIRS = [
    ("N", -1, 0),
    ("S", 1, 0),
    ("E", 0, 1),
    ("W", 0, -1),
]

INF = 10**18
GOAL_MASK = (1 << 6) - 1


# lee una sola instancia
def read_input():
    data = stdin.read().splitlines()
    out = None

    if len(data) > 0:
        R, C, A, B = map(int, data[0].split())
        grid = []
        i = 1

        while i < 1 + R and i < len(data):
            grid.append(data[i].rstrip("\n"))
            i += 1

        out = (R, C, A, B, grid)

    return out


# busca donde empieza y marca el oro con bits
def build_map(grid):
    start = (-1, -1)
    gold_map = {}
    i = 0

    while i < len(grid):
        j = 0
        while j < len(grid[i]):
            if grid[i][j] == "S":
                start = (i, j)
            elif grid[i][j] == "G":
                gold_map[(i, j)] = len(gold_map)
            j += 1
        i += 1

    return start, gold_map


# orientacion del cubo: (top, bottom, north, south, east, west)
def rot(ori, d):
    top, bottom, north, south, east, west = ori
    nxt = ori

    if d == "N":
        nxt = (south, north, top, bottom, east, west)
    elif d == "S":
        nxt = (north, south, bottom, top, east, west)
    elif d == "E":
        nxt = (west, east, north, south, top, bottom)
    elif d == "W":
        nxt = (east, west, north, south, bottom, top)

    return nxt


# falta una parte aqui pero la dejp medio lista
# luego toca meter bien el cambio de oro en la cara y en la grilla
def nxt_state(state, d, gold_map, grid):
    r, c, ori, cube_gold, left_gold = state
    dr = 0
    dc = 0
    i = 0

    while i < len(DIRS):
        if DIRS[i][0] == d:
            dr = DIRS[i][1]
            dc = DIRS[i][2]
        i += 1

    nr = r + dr
    nc = c + dc
    next_state = state
    picked = False

    if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]):
        nori = rot(ori, d)

        # aca falta la parte fina:
        # - mirar si la celda tiene oro
        # - mirar si la cara de abajo tiene oro
        # - mover el oro entre celda y cubo
        # por ahora se deja la transicion de posicion y giro
        next_state = (nr, nc, nori, cube_gold, left_gold)

    return next_state, picked


# costo del movimiento
def mov_cost(picked, A, B):
    cost = A
    if picked:
        cost = B
    return cost


# dijkstra sobre el grafo de estados
def dijkstra(R, C, A, B, grid, start, gold_map):
    s_ori = (0, 1, 2, 3, 4, 5)
    left_gold = (1 << len(gold_map)) - 1
    init = (start[0], start[1], s_ori, 0, left_gold)

    dist = {init: 0}
    pq = []
    heappush(pq, (0, init))

    ans = None

    while len(pq) > 0 and ans is None:
        cur_d, state = heappop(pq)

        if dist.get(state, INF) == cur_d:
            r, c, ori, cube_gold, left_gold = state

            if left_gold == 0 and cube_gold == GOAL_MASK:
                ans = cur_d
            else:
                k = 0
                while k < len(DIRS) and ans is None:
                    d = DIRS[k][0]
                    ns, picked = nxt_state(state, d, gold_map, grid)
                    nd = cur_d + mov_cost(picked, A, B)

                    if nd < dist.get(ns, INF):
                        dist[ns] = nd
                        heappush(pq, (nd, ns))

                    k += 1

    return ans


# resuelve la instancia
def solve_case(R, C, A, B, grid):
    start, gold_map = build_map(grid)
    ans = dijkstra(R, C, A, B, grid, start, gold_map)

    out = "Oh my God, they killed Kenny!"
    if ans is not None:
        out = f"Screw you guys, I got all the gold for {ans} cost!"

    return out


# main
def main():
    data = read_input()
    out = ""

    if data is not None:
        R, C, A, B, grid = data
        out = solve_case(R, C, A, B, grid)

    if out != "":
        print(out)

    return


#main()
