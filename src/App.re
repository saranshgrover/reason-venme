[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();
    let (started, setStarted) = React.useState(() => false);

    <>
     {switch (url.path, started) {
     | (["about"], _) => <div>{React.string("about")}</div>
     | (_, false) => <Home onStart={(_) => setStarted((_) => true)}/>
     | (_, true) => <Landing/>
     };}
    </>
}