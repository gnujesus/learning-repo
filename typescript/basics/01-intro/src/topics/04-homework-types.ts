type Address = {
    calle: string,
    pais: string,
    ciudad: string,
};

interface SuperHeroe {
    name: string;
    age: number;
    address: Address;
    showAddress: () => string;
}

const superHeroe: SuperHeroe = {
    name: 'Spiderman',
    age: 30,
    address: {
        calle: 'Main St',
        pais: 'USA',
        ciudad: 'NY'
    },
    showAddress: function (): string {
        return this.name + ', ' + this.address.ciudad + ', ' + 'idk what else';
    }
};

console.log(superHeroe.showAddress());