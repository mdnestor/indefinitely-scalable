

#ELEMENT ANT // ant
void update_ant(cell_t* cell) {
    PATTERN
        |  a
        | a.a  
        |  a;

    //ant* cell = (void*) cell;
    
    if (a->type == FOOD) {
        // if you don't have food, eat the food
        if (cell->data[0] == 0) {
            cell->data[0] = 1; 
            cell->data[1] = 1;
            a->type = BLANK;
        // if you have food, update the counter
        } else if (cell->data[0] == 1) {
            cell->data[1] = 1;
        }
    } else if (a->type == COLONY && cell->data[0] == 1) {
        a->data[0] = 1;
        cell->data[0] = 0;
        cell->data[1] = 1;
    } else if (a->type == BLANK) {
        // if have food 
        if (cell->data[0] == 1) {
            // if trail is food
            if (a->data[0] == 1) {
                // if trail closer to food
                if (a->data[1] < cell->data[1]) {
                    // move to trail
                    cell->data[1] = a->data[1];
                    a->data[1] = a->data[1] + 1;
                    swap_cells(a, cell);
                // otherwise its farther 
                } else if (a->data[1] > cell->data[1]) {
                    a->data[1] = cell->data[1] + 1;
                }
            // else you need food but the target isnt food trail
            } else if (randp(20)) {
                a->data[1] = cell->data[1];
                cell->data[1] = cell->data[1] + 1;
                swap_cells(a, cell);
            }
        // other, you need food. if you switch with food trail then increment it by one
        } else if (randp(20)) {
            swap_cells(a, cell);
        }
    }
    0;
}

#ELEMENT COLONY // colony
void update_colony(cell_t* cell) {
    PATTERN
        |  a
        | a.a  
        |  a;

    //colony* cell = (void*) cell;
    
    if (a->type == BLANK && cell->data[0] == 1) {
        a->type = ANT;
        cell->data[0] = 0;
    }
}


#ELEMENT FOOD // food
void update_food(cell_t* cell) {
    0;
}




