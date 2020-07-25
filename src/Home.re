let str = React.string;
let logo: string = [%raw "require('./assets/logo.png')"];

[@react.component]
let make = (~onStart) => {

  let (fadeout, setFadeout) = React.useState(() => false);
  
  React.useEffect1(() => {
    if(fadeout) {
      let timeout = Js.Global.setTimeout(() => onStart(), 500);
      Some(() => Js.Global.clearTimeout(timeout))
    }
    else {
    None
    }
  },[|fadeout|])

  let className = Cn.([%tw "h-screen flex justify-center items-center transition-all duration-500 ease-in-out"] <:> [%tw "opacity-100"]->on(!fadeout) <:> [%tw "opacity-0"]->on(fadeout));
  <div className>
    <div className="max-w-sm rounded overflow-hidden shadow-lg">
      <img className="w-full" src=logo alt="Venme" />
      <div className="px-6 py-4">
        <div className="font-bold text-Ixl text-white mb-2 text-center"> {"The act of receiving a money transaction using the Venmo app." |> str} </div>
      </div>
      <div className="flex justify-center px-6 py-4">
       <button className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded" onClick={(_) => setFadeout((_) => true)}>
          {"Get Started" |> str}
        </button> 
      </div>
    </div>
  </div>

};
