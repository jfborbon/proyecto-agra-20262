# lectura de datos
#def read_input():


# Convierte la orientación del cubo al moverlo hacia el norte
#def roll_north(state):


# Convierte la orientación del cubo al moverlo hacia el sur
#def roll_south(state):


# Convierte la orientación del cubo al moverlo hacia el este
#def roll_east(state):


# Convierte la orientación del cubo al moverlo hacia el oeste
#def roll_west(state):


# Obtiene los estados vecinos posibles desde un estado dado
#def get_neighbors(state):


# Ejecuta Dijkstra sobre el grafo de estados
#def dijkstra(grid, start, gold_positions, A, B):


# Verifica si un estado ya representa que se recolectó todo el oro
#def is_goal(state):



def main():
    T = int(input())
    
    for _ in range(T):
        R, C, A, B = map(int, input().split())
        grid = [input().strip() for _ in range(R)]
        
        # Aqui se procesaría cada caso de prueb y se imprimiría la respuesta correspondiente
        pass


#main()