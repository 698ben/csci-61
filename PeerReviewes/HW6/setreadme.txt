The implementation is not complete.

Still need:

private:
std::size_t erase(const Item& target);
std::size_t count(const Item& target) const;
void print(int indent) const;

public:
bool loose_insert(const Item& entry);
bool loose_erase(const Item& target);
void remove_biggest(Item& removed_entry);
void fix_shortage(std::size_t i);

Do we need to write set.template as well?
