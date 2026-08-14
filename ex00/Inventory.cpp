#include "Inventory.hpp"

void Inventory::add(const std::string &item) { (void)item; }

void Inventory::remove(const std::string &item) { (void)item; }

bool Inventory::has(const std::string &item) const {
  (void)item;
  return true;
}

int Inventory::count() const { return m_items.size(); }
