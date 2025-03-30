interface Human {
    name: string;
    walk: () => void;
    talk: () => void;
}

class Employee implements Human {
    name: string;

    constructor(name: string) {
        this.name = name;
    };

    walk = function () {
        console.log('Walking');;
    };

    talk = function () {
        console.log('Blah blah');;
    };

    whoAmI = () => { console.log(this.name); };
}

const jesus: Employee = new Employee('Jesus');

jesus.talk();
jesus.walk();
jesus.whoAmI();