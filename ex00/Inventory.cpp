#include "Inventory.hpp"

#include <algorithm>

void Inventory::add(const std::string &item) { m_items.push_back(item); }

void Inventory::remove(const std::string &item) {
  (void)item;
  m_items.clear();
}

bool Inventory::has(const std::string &item) const {
  return std::find(m_items.begin(), m_items.end(), item) != m_items.end();
}

int Inventory::count() const { return m_items.size(); }
