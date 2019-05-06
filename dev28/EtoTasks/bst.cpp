void show_pair(const IComparable& key, const Object& value)

{

  printf(“%s: %s\n”, key.to_string().data(), value.to_string().data());

}

 

int main()

{

  bst b;

  b.add(new Integer(1), new String(“uno”));

  b.add(new Integer(10), new String(“diez”));

  b.add(new Integer(5), new String(“cinco”)); 

  b.add(new Integer(8), new String(“ocho”));

  b.add(new Integer(7), new String(“siete”));

  b.add(new Integer(2), new String(“dos”));

 

  b.iterate(show_pair);

 

  Object* obj;

 if (b.try_find(Integer(2), obj))

     puts(obj->to_string().data());

  else

     puts(“Not found”);

 

  return 0;

}