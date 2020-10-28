class Cs:
    @staticmethod
    def static_method():
        print("static")

    @classmethod
    def class_method(cls):
        print("class")

    def instance_method(self):
        print("instance")

i=Cs()
Cs.static_method()
Cs.class_method()
i.instance_method()