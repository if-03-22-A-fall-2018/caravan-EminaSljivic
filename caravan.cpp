/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "caravan.h"
#include <stdlib.h>
#include "general.h"

struct NodeImplementation{
  void* data;
  Node next;
};

struct CaravanImplementation{
  Node head;
};

Caravan new_caravan()
{
  Caravan caravan=(Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head=0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count=0;
  Node currNode=caravan->head;

  while (currNode!=0) {
    count++;
    currNode=currNode->next;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  Node currNode=caravan->head;
  Node toBeDeleted;

  while(currNode!=0){
    toBeDeleted=currNode;
    currNode=currNode->next;
    sfree(toBeDeleted);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal!=0)
  {
    if(get_caravan(animal)!=0)
    {
      remove_pack_animal(get_caravan(animal),animal);
    }
    Node newNode=(Node)malloc(sizeof(struct NodeImplementation));
    add_to_caravan(animal,caravan);
    newNode->data=animal;
    newNode->next=caravan->head;
    caravan->head=newNode;
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(caravan->head==0||animal==0)
    return;
  if(caravan->head->data==animal)
  {
    Node toBeDeleted=caravan->head;
    caravan->head=caravan->head->next;
    sfree(toBeDeleted);
  }
  else{
    Node currNode=caravan->head;
    while(currNode->next != 0 && currNode->next->data != animal){
      currNode = currNode->next;
    }

    if(currNode->next != 0){
      Node toBeDeleted=currNode->next;
      currNode->next=currNode->next->next;
      sfree(toBeDeleted);
    }
  }
  add_to_caravan(animal,0);
}

int get_caravan_load(Caravan caravan)
{
  int load=0;

  Node currNode=caravan->head;
  while(currNode!=0){
    load+=get_load((PackAnimal)currNode->data);
    currNode=currNode->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node currNode=caravan->head;
  while(currNode!=0){
    unload((PackAnimal)currNode->data);
    currNode=currNode->next;
    }
}

int get_caravan_speed(Caravan caravan)
{
  if(caravan->head!=0){
    Node currNode=caravan->head;
    int min_speed=get_actual_speed((PackAnimal)currNode->data);
    while(currNode!=0){
      if(min_speed>get_actual_speed((PackAnimal)currNode->data))
      {
        min_speed=get_actual_speed((PackAnimal)currNode->data);
      }
      currNode=currNode->next;
  }
  return min_speed;
  }
  return 0;
}
