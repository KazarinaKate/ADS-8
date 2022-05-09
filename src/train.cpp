// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : count(0), head(nullptr) {}
void Train::addCage(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->prev = nullptr;
  cage->next = nullptr;
  if (head == nullptr) {
    head = cage;
  } else if (first->next == nullptr) {
    head->next = cage;
    cage->prev = head;
    head->prev = cage;
    cage->next = head;
  } else {
    head->prev->next = cage;
    cage->prev = head->prev;
    head->prev = cage;
    cage->next = head;
  }
}

int Train::getLength() {
  Cage* current = head;
  head->light = true;
  int lenght = 0;
  count = 0;
  while (true) {
    count++;
    lenght++;
    int tr_lenght;
    current = current->next;
    if (current->light) {
      current->light = false;
      tr_lenght = lenght;
      for (tr_lenght; tr_lenght > 0; tr_lenght--) {
        current = current->prev;
        count++;
      }
      if (!current->light) {
        return lenght;
      }
      lenght = tr_lenght;
    }
  }
}
int Train::getOpCount() {
  return count;
}
