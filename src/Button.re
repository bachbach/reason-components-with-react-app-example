let str = ReasonReact.string;

let component = ReasonReact.statelessComponent("Button");

let make = (~buttonType, ~onClick, ~children) => {
  {
    ...component,
    render: (self) =>
      <button
        type_=buttonType
        onClick=onClick
      >
        (children)
      </button>
  }
};

[@bs.deriving abstract]
type jsProps = {
  buttonType: string,
  onClick: ReactEvent.Mouse.t => unit,
  children: ReasonReact.reactElement
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~buttonType=jsProps##buttonType,
      ~onClick=jsProps##onClick,
      ~children=jsProps##children,
    )
  );