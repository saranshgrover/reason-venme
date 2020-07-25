let str = React.string;
let logo: string = [%raw "require('./assets/logo.png')"];

[@react.component]
let make = () => {
    let init: TransactionTypes.transaction = {
        total: 0.0,
        tax: 0.0,
        tip: 0.0,
        tipPercent: 15.0,
        totalPeople: 0,
        persons: [],
        state: BEGIN
    };
    let (transaction, setTransaction) = React.useState(() => init);

    let (passAlongMode, setPassAlongMode) = React.useState(() => true);


    let addPerson = (person: TransactionTypes.person) => setTransaction((_) => {...transaction, persons: transaction.persons @ [person] });

    <>
        {switch transaction.state {
        | BEGIN => <BeginInputForm transaction=transaction setTransaction=setTransaction setPassAlongMode=setPassAlongMode passAlongMode=passAlongMode />
        | BEGAN when List.length(transaction.persons) != transaction.totalPeople => <PersonInputForm transaction=transaction whenDone=addPerson />
        | BEGAN => <ConfirmComplete/>
        | COMPLETE => <Complete/>
        };}
    </>
}