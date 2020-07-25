
type state = 
| BEGIN
| BEGAN
| COMPLETE;


type person = {
    name: option(string),
    venmoId: string,
    amountPaying: string
};

type transaction = {
    total: float,
    tax: float,
    tip: float,
    tipPercent: float,
    state: state,
    totalPeople: int,
    persons: list(person)
};
