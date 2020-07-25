let str = React.string;
let logo: string = [%raw "require('./assets/logo.png')"];

type styles = {
  input: string,
  label: string
};

[@react.component]
let make = (~transaction: TransactionTypes.transaction , ~setTransaction, ~setPassAlongMode, ~passAlongMode: bool) => {
  
  let (formInfo, setFormInfo) = React.useState(() => transaction);

  let {total, tip, tipPercent, tax, totalPeople} : TransactionTypes.transaction = transaction

  let form = FormConfig.BeginInputFormality.useForm(~initialInput={total,tip,tipPercent,tax,totalPeople}, ~onSubmit=(output, cb) => (
    Js.log("hello?")
  ))


  let styles = {
    input: [%tw "shadow appearance-none border rounded py-2 px-3 text-black leading-tight focus:outline-none focus:shadow-outline align-middle"],
    label: [%tw "block text-white text-sm font-bold mb-2"]
  };

  let onSubmit = e => {
    ReactEvent.Form.preventDefault(e);
    form.submit()
  };
  <div className=[%tw "max-w-sm sm:max-w-md md:max-w-lg lg:max-w-xl container mx-auto p-8 bg-black flex-col justify-center content-center items-center"]>
    <img className=[%tw " pt-4 w-2/6 m-auto object-contain py-4"] src=logo alt="Venme" />
    <form onSubmit className=[%tw "bg-gray-800 shadow-lg rounded p-8 pt-6"]>
      <div className=[%tw "mb-4 text-center"]>
        <label className=styles.label htmlFor="total">{"Total" |> str}</label>
        <span className="currency-input">
        <input id="total" placeholder="Total" type_="number" step=0.001 disabled={form.submitting} onBlur={_=>form.blurTotal()} value={Js.Float.toString(form.input.total)} onChange={e => form.updateTotal((input, value) => {...input, total: value}, e->ReactEvent.Form.target##value)} className=Cn.(styles.input <:> [%tw "pl-5"])/>
        </span>
        {switch(form.totalResult) {
          | Some(Error(msg)) => <div className=[%tw "text-red-500"]> {msg |> str} </div> 
          | _ => React.null
        }}
      </div>
      <div className=[%tw "mb-4 text-center"]>
        <label className=styles.label htmlFor="tax">{"Tax" |> str}</label>
        <span className="currency-input">
        <input id="tax" placeholder="Tax" type_="number" step=0.001 disabled={form.submitting} onBlur={_=>form.blurTax()} value={Js.Float.toString(form.input.tax)} onChange={e => form.updateTax((input, value) => {...input, tax: value}, e->ReactEvent.Form.target##value)} className=Cn.(styles.input <:> [%tw "pl-5"])/>
        </span>
        {switch(form.taxResult) {
          | Some(Error(msg)) => <div className=[%tw "text-red-500"]> {msg |> str} </div> 
          | _ => React.null
        }}
      </div>
      <div className=[%tw "mb-4 text-center"]>
        <label className=styles.label htmlFor="tipPercent">{"Tip Percent %" |> str}</label>
        <span className="percent-input">
        <input id="tipPercent" placeholder="Total" type_="number" step=0.001 disabled={form.submitting} onBlur={_=>form.blurTipPercent()} value={Js.Float.toString(form.input.tipPercent)} onChange={e => form.updateTipPercent((input, value) => {...input, tipPercent: value}, e->ReactEvent.Form.target##value)} className=Cn.(styles.input <:> [%tw "pl-5"])/>
        </span>
        {switch(form.tipPercentResult) {
          | Some(Error(msg)) => <div className=[%tw "text-red-500"]> {msg |> str} </div> 
          | _ => React.null
        }}
      </div>
      <div className=[%tw "mb-4 text-center"]>
        <label className=styles.label htmlFor="tipPercent">{"Tip" |> str}</label>
        <span className="currency-input">
        <input id="tip" placeholder="Tip" type_="number" step=0.01 disabled={form.submitting} onBlur={_=>form.blurTip()} value={Js.Float.toString(form.input.tip)} onChange={e => form.updateTip((input, value) => {...input, tip: value}, e->ReactEvent.Form.target##value)} className=Cn.(styles.input <:> [%tw "pl-5"])/>
        </span>
        {switch(form.tipResult) {
          | Some(Error(msg)) => <div className=[%tw "text-red-500"]> {msg |> str} </div> 
          | _ => React.null
        }}
      </div>
      <div className=[%tw "mb-4 text-center"]>
        <label className=styles.label htmlFor="totalPeople">{"How many people are splitting?" |> str}</label>
        <input id="tip" placeholder="Tip" type_="number" step=1.0 disabled={form.submitting} onBlur={_=>form.blurTotalPeople()} value={Js.Int.toString(form.input.totalPeople)} onChange={e => form.updateTotalPeople((input, value) => {...input, totalPeople: value}, e->ReactEvent.Form.target##value)} className=styles.input/>        
        {switch(form.totalPeopleResult) {
          | Some(Error(msg)) => <div className=[%tw "text-red-500"]> {msg |> str} </div> 
          | _ => React.null
        }}
      </div>
      <div className="flex justify-center px-6 py-4">
       <button disabled={form.submitting} className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
          {"Next" |> str}
        </button> 
      </div>
    </form>
  </div>
}