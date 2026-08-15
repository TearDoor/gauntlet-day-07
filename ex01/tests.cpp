
#include "catch_amalgamated.hpp"

#include "Inventory.hpp"

struct InventoryFixture {
  Inventory inv;

  InventoryFixture() {
    inv.add("potion");
    inv.add("sword");
  }
};

TEST_CASE_METHOD(InventoryFixture, "adding an item raises the count") {
  int before = inv.count();
  inv.add("elixir");
  CHECK(inv.count() == before + 1);
}

TEST_CASE_METHOD(InventoryFixture,
                 "has() finds an added item and rejects a missing one") {
  CHECK(inv.has("potion") == true);
  CHECK(inv.has("elixir") == false);
}

TEST_CASE_METHOD(InventoryFixture, "removing an item drops the count") {
  int before = inv.count();
  inv.remove("potion");
  CHECK(inv.count() == before - 1);
  CHECK(inv.has("potion") == false);
}

TEST_CASE_METHOD(InventoryFixture, "removing a missing item is a no-op") {
  int before = inv.count();
  inv.remove("elixir");
  CHECK(inv.count() == before);
  CHECK(inv.has("potion"));
  CHECK(inv.has("sword"));
}
