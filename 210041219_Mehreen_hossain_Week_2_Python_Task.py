def process_instructions(instruct, grid):
    n = len(instruct)
    dir = ['N','E','S','W']
    cur_dir = 0
    cur_pos_x = 0
    cur_pos_y = 0
    
    for i in range(0, n):
        if instruct[i] == 'F' and (cur_dir) % 2:
            if cur_dir == 1 and cur_pos_x < int(grid[0]): 
                cur_pos_x = cur_pos_x + 1
            elif cur_dir == 3 and cur_pos_x != 0: 
                cur_pos_x = cur_pos_x - 1
        elif instruct[i] == 'F' and (cur_dir) % 2==0:
            if cur_dir == 0 and cur_pos_y < int(grid[1]): 
                cur_pos_y = cur_pos_y + 1
            elif cur_dir == 2 and cur_pos_y != 0 : 
                cur_pos_y = cur_pos_y - 1
        elif instruct[i] == 'L':
            cur_dir = cur_dir - 1
            if(cur_dir < 0): cur_dir = 3
        elif instruct[i] == 'R':
            cur_dir = cur_dir + 1
            if(cur_dir > 3): cur_dir = 0
                
    print("current position: " + str(cur_pos_x) + " " + str(cur_pos_y))
    print("current direction: " + dir[cur_dir])
            

instructions = input()
grid_size = list((input().split()))
print(process_instructions(instructions, grid_size))
