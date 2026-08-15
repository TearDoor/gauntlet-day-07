#include "catch_amalgamated.hpp"

#include "Inventory.hpp"

TEST_CASE("adding an item raises the count") {
  Inventory inv;
  int before = inv.count();

  inv.add("potion");
  CHECK(inv.count() == before + 1);
}

TEST_CASE("has() finds an added item and rejects a missing one") {
  Inventory inv;

  inv.add("potion");
  CHECK(inv.has("potion") == true);
  CHECK(inv.has("sword") == false);
}

TEST_CASE("removing an item drops the count and has() stops finding it") {
  Inventory inv;
  inv.add("potion");
  int before = inv.count();
  inv.remove("potion");
  CHECK(inv.count() == before - 1);
  CHECK(inv.has("potion") == false);
}

TEST_CASE("removing a missing item is a no-op: count unchanged, other items "
          "untouched") {
  Inventory inv;
  inv.add("potion");

  int before = inv.count();
  inv.remove("sword");              // missing item
  CHECK(inv.count() == before);     // should be same as before
  CHECK(inv.has("potion") == true); // should still be inside
}
